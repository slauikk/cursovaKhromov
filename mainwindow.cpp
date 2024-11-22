#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , dbManager(new SqliteDBManager("jopa.db"))
    , addOutlay(new AddOutlayDialog(this, dbManager))
    , addProfile(new AddProfileDialog(this))
    , exchangeDialog(new ExchangeDialog(this))
    , analysisDialog(new AnalysisDialog(this))
    , model(new QSqlRelationalTableModel(this))
{
    ui->setupUi(this);
    this->setWindowTitle("Monyfine");
    dbManager->createTables();
    setupOutlayView();
    loadProfiles();

    connect(addProfile, &AddProfileDialog::profileCreated, this, &MainWindow::onProfileCreated);
    connect(ui->cb_profiles, SIGNAL(currentIndexChanged(int)), this, SLOT(on_cb_profiles_currentIndexChanged(int)));
    connect(addOutlay, &AddOutlayDialog::outlayCreated, this, [this](Outlay* outlay) {
        dbManager->insertOutlay(outlay);
        loadOutlayData();
        int profileId = ui->cb_profiles->currentData().toInt();
        updateOutlayView(profileId);
        updateOutlayChart(profileId);
        delete outlay;
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_addOutlay_clicked()
{
    int currentProfileIndex = ui->cb_profiles->currentIndex();
    if (currentProfileIndex == -1) {
        QMessageBox::warning(this, "Помилка", "Виберіть профіль перед створенням витрати.");
        return;
    }

    int profileId = ui->cb_profiles->currentData().toInt();
    addOutlay->setProfileId(profileId);

    addOutlay->exec();
}



void MainWindow::on_pb_searchOutlay_clicked()
{
    QString searchText = ui->le_searchOutlay->text();

    int profileId = ui->cb_profiles->currentData().toInt();

    QString filter;

    if (profileId != 0) {
        filter += QString("profile_id = %1").arg(profileId);
    }

    if (!searchText.isEmpty()) {
        if (!filter.isEmpty()) {
            filter += " AND ";
        }
        filter += QString("name LIKE '%%1%' OR amount LIKE '%%1%' OR timestamp LIKE '%%1%'").arg(searchText);
    }

    if (!filter.isEmpty()) {
        model->setFilter(filter);
    } else {
        model->setFilter("");
    }

    model->select();
}




void MainWindow::on_pb_addProfile_clicked()
{
    addProfile->exec();
}


void MainWindow::on_pb_exchange_clicked()
{
    exchangeDialog->exec();
}


void MainWindow::on_pb_analysis_clicked()
{
    int profileId = ui->cb_profiles->currentData().toInt();

    analysisDialog->setProfileId(profileId);
    analysisDialog->exec();
}


void MainWindow::on_pb_exit_clicked()
{
    QApplication::exit();
}

void MainWindow::setupOutlayView() {
    model->setTable("Outlays");

    model->setHeaderData(0, Qt::Horizontal, "ID");
    model->setHeaderData(1, Qt::Horizontal, "Назва витрати");
    model->setHeaderData(3, Qt::Horizontal, "Категорія");
    model->setHeaderData(4, Qt::Horizontal, "Сума");
    model->setHeaderData(5, Qt::Horizontal, "Час");

    model->setRelation(2, QSqlRelation("Profiles", "id", "profile_name"));
    model->setRelation(3, QSqlRelation("Categories", "id", "category_name"));

    ui->tv_outlay->setModel(model);

    ui->tv_outlay->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tv_outlay->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tv_outlay->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tv_outlay->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tv_outlay->verticalHeader()->setVisible(false);

    ui->tv_outlay->hideColumn(0);
    ui->tv_outlay->hideColumn(2);
}


void MainWindow::loadOutlayData() {
    model->select();
    if (model->lastError().isValid()) {
        qDebug() << "Error loading data into outlay table:" << model->lastError();
    } else {
        qDebug() << "Outlay data loaded successfully.";
    }
}

void MainWindow::onProfileCreated(Profile *profile)
{
    if (dbManager->insertProfile(profile)) {
        qDebug() << "Profile inserted successfully.";
        QMessageBox::information(this, "Успіх", "Профіль успішно створено.");
    } else {
        qDebug() << "Failed to insert profile.";
        QMessageBox::critical(this, "Помилка", "Не вдалося створити профіль.");
    }
    loadOutlayData();
    loadProfiles();
    delete profile;
}

void MainWindow::loadProfiles() {

    ui->cb_profiles->clear();

    QSqlQuery query;
    query.exec("SELECT id, profile_name FROM Profiles");

    while (query.next()) {
        int id = query.value(0).toInt();
        QString profileName = query.value(1).toString();

        ui->cb_profiles->addItem(profileName, id);
    }
}


void MainWindow::on_cb_profiles_currentIndexChanged(int index) {
    int profileId = ui->cb_profiles->currentData().toInt();

    updateOutlayView(profileId);
    updateOutlayChart(profileId);
}


void MainWindow::updateOutlayView(int profileId) {
    qDebug() << "Updating Outlay view for profile ID: " << profileId;
    QString filter = QString("profile_id = %1").arg(profileId);
    qDebug() << "Filter applied: " << filter;


    model->setFilter(filter);
    model->select();
}

#include <QGraphicsGridLayout>

void MainWindow::updateOutlayChart(int profileId)
{
    qDebug() << "Updating Outlay chart for profile ID: " << profileId;

    QSqlQuery categoryQuery("SELECT id, category_name FROM Categories");
    QMap<int, QString> categories;

    while (categoryQuery.next()) {
        int categoryId = categoryQuery.value(0).toInt();
        QString categoryName = categoryQuery.value(1).toString();
        categories.insert(categoryId, categoryName);
    }

    QPieSeries *series = new QPieSeries();

    QVector<QColor> rainbowColors = {
        QColor("#FF0000"), // Червоний
        QColor("#FF7F00"), // Оранжевий
        QColor("#FFFF00"), // Жовтий
        QColor("#00FF00"), // Зелений
        QColor("#0000FF"), // Синій
        QColor("#4B0082"), // Індиго
        QColor("#8A2BE2")  // Фіолетовий
    };

    QVector<QColor> allColors;
    int totalCategories = categories.size();

    for (int i = 0; i < totalCategories; ++i) {
        int colorIndex = i % rainbowColors.size();
        QColor baseColor = rainbowColors[colorIndex];

        int hue = baseColor.hue() + (i * 10) % 360;
        QColor newColor = QColor::fromHsv(hue, baseColor.saturation(), baseColor.value());
        allColors.append(newColor);
    }

    int colorIndex = 0;
    for (auto categoryId : categories.keys()) {
        QSqlQuery sumQuery;
        sumQuery.prepare("SELECT SUM(amount) FROM Outlays WHERE profile_id = :profileId AND category_id = :categoryId");
        sumQuery.bindValue(":profileId", profileId);
        sumQuery.bindValue(":categoryId", categoryId);
        sumQuery.exec();

        if (sumQuery.next()) {
            double sum = sumQuery.value(0).toDouble();
            if (sum > 0) { // Додаємо тільки якщо сума більше нуля
                QString categoryName = categories.value(categoryId);
                QPieSlice *slice = series->append(categoryName, sum);

                slice->setLabel(categoryName + "\n" + QString::number(sum, 'f', 2));
                slice->setLabelVisible(false);

                // Призначаємо колір кожному сегменту
                slice->setBrush(allColors[colorIndex]);

                colorIndex++;
            }
        }
    }

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Сума витрат по категоріях");

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    chart->legend()->setAlignment(Qt::AlignBottom);
    chart->legend()->setMarkerShape(QLegend::MarkerShapeRectangle);

    QLayoutItem *item;
    while ((item = ui->horizontalLayout->takeAt(0)) != nullptr) {
        delete item->widget();
        delete item;
    }

    ui->horizontalLayout->addWidget(chartView);
}


