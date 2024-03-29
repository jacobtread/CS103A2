#include "Stores.hpp"

DataObjectCollection Stores::users = DataObjectCollection("users.db");
DataObjectCollection Stores::tripTransactions =
    DataObjectCollection("tripTransactions.db");
DataObjectCollection Stores::lostItems = DataObjectCollection("lostItems.db");
DataObjectCollection Stores::complaints = DataObjectCollection("complaints.db");
User* Stores::activeUser = nullptr;

DataObjectCollection* Stores::getUsers() {
    return &Stores::users;
}

DataObjectCollection* Stores::getTripTransactions() {
    return &Stores::tripTransactions;
}

DataObjectCollection* Stores::getLostItems() {
    return &Stores::lostItems;
}

DataObjectCollection* Stores::getComplaints() {
    return &Stores::complaints;
}

void Stores::setActiveUser(User* activeUser) {
    // Delete the existing active user if one is present
    if (Stores::activeUser != nullptr) {
        delete Stores::activeUser;
    }

    Stores::activeUser = activeUser;
}

User* Stores::getActiveUser() {
    return Stores::activeUser;
}

void Stores::load() {
    users.load();
    tripTransactions.load();
    lostItems.load();
    complaints.load();
}

void Stores::save() {
    users.save();
    tripTransactions.save();
    lostItems.save();
    complaints.save();
}