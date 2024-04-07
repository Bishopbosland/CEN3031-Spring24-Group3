#include <iostream> 
#include "ParkingSpace.hpp"
using namespace std; 

#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <vector>
#include <string>

class ParkingSpace {
private:
    int spaceID;
    bool isOccupied;
    bool isUnderMaintenance;
    string vehicleLicense;
public:
    ParkingSpace(int id);
    void occupySpace(const string& license);
    void freeSpace();
    void markUnderMaintenance();
    void markAvailable();
    bool checkOccupied() const;
    int getSpaceID() const;
    string getStatus() const;
};

ParkingSpace::ParkingSpace(int id) : spaceID(id), isOccupied(false), isUnderMaintenance(false), vehicleLicense("") {}

void ParkingSpace::occupySpace(const string& license) {
    if (!isOccupied && !isUnderMaintenance) {
    isOccupied = true;
    vehicleLicense = license;
    }
}

void ParkingSpace::freeSpace() {
    if (isOccupied) {
        isOccupied = false;
        vehicleLicense = "";
    }
}

void ParkingSpace::markUnderMaintenance() {
    if (!isOccupied) {
        isUnderMaintenance = true;
    }
}

void ParkingSpace::markAvailable() {
    isUnderMaintenance = false;
}

bool ParkingSpace::checkOccupied() const {
    return isOccupied;
}

int ParkingSpace::getSpaceID() const {
    return spaceID;
}

string ParkingSpace::getStatus() const {
    if (isUnderMaintenance) {
        return "Under Maintenance";
    } else if (isOccupied) {
        return "Occupied by " + vehicleLicense;
    } else {
        return "Available";
    }
}

class ParkingSystemGUI : public QWidget {
    Q_OBJECT

public:
    ParkingSystemGUI(QWidget *parent = 0)
    ~ParkingSystemGUI();

private slots: 
    void occupySpace();
    void freeSpace();
    void markMaintenance();
    void updateStatus();

private:
    vector<ParkingSpace> parkingLot;
    QVBoxLayout *mainLayout;
    QLabel *statusLabel;
    QPushButton *occupyButton;
    QPushButton *freeButton;
    QPushButton *maintenanceButton;
    QPushButton *updateButton;
};

ParkingSystemGUI::ParkingSystemGUI(QWidget *parent)
    : QWidget(parent)
{
    mainLayout = new QVBoxLayout;
    setLayout(mainLayout);

    statusLabel = new QLabel;
    mainLayout->addWidget(statusLabel);

    for (int i = 1; i <= 10; ++i) {
        parkingLot.emplace_back(i);
    }

    occupyButton = new QPushButton("Occupy Space");
    connect(occupyButton, &QPushButton::clicked, this, &ParkingSystemGUI::occupySpace);
    mainLayout->addWidget(occupyButton);

    freeButton = new QPushButton("Free Space");
    connect(freeButton, &QPushButton::clicked, this, &ParkingSystemGUI::freeSpace);
    mainLayout->addWidget(freeButton);

    maintenanceButton = new QPushButton("Mark Maintenance");
    connect(maintenanceButton, &QPushButton::clicked, this, &ParkingSystemGUI::markMaintenance);
    mainLayout->addWidget(maintenanceButton);

    updateButton = new QPushButton("Update Status");
    connect(updateButton, &QPushButton::clicked, this, &ParkingSystemGUI::updateStatus);
    mainLayout->addWidget(updateButton);
}

ParkingSystemGUI::~ParkingSystemGUI()
{
}

void ParkingSystemGUI::occupySpace() {
    for (auto& space : parkingLot) {
        if (!space.checkOccupied()) {
            space.occupySpace("License Plate");
            break;
        }
    }
    updateStatus();
}

void ParkingSystemGUI::freeSpace() {
    for (auto& space : parkingLot) {
        if (space.checkOccupied()) {
            space.freeSpace();
            break;
        }
    }
    updateStatus();
}

void ParkingSystemGUI::markMaintenance() {
    for (auto& space : parkingLot) {
        if (!space.checkOccupied()) {
            space.markUnderMaintenance();
            break;
        }
    }
    updateStatus();
}

void ParkingSystemGUI::updateStatus() {
    QString statusText;
    for (const auto& space : parkingLot) {
        statusText += "Parking Space " + QString::number(space.getSpaceID()) + " is " + QString::fromStdString(space.getStatus()) + ".\n";
    }
    statusLabel->setText(statusText);
}

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    ParkingSystemGUI gui;
    gui.setWindowTitle("Parking Space Management");
    gui.show();

    return app.exec();
}

#include "main.moc"
