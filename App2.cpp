#include <bits/stdc++.h>
using namespace std;
class Login {
protected:
    map<string, string> doctorLogin;

public:
    Login() {
        doctorLogin["doc101"] = "pass123";
        doctorLogin["doc102"] = "heart456";
    }

    bool doctorLoginCheck(string &loggedDoctor) {
        string id, pass;

        cout << "\nEnter Doctor ID: ";
        cin >> id;

        cout << "Enter Password: ";
        cin >> pass;

        if (doctorLogin.find(id) != doctorLogin.end() &&
            doctorLogin[id] == pass) {
            loggedDoctor = id;
            cout << "\nDoctor Login Successful!\n";
            return true;
        }

        cout << "\nInvalid Doctor Login!\n";
        return false;
    }
};

class Medicine {
protected:
    vector<string> medicineList;

public:
    Medicine() {
        medicineList.push_back("Paracetamol");
        medicineList.push_back("Dolo650");
        medicineList.push_back("Azithromycin");
        medicineList.push_back("Crocin");
        medicineList.push_back("VitaminC");
    }

    void showMedicines() {
        cout << "\n===== Available Medicines =====\n";

        for (int i = 0; i < medicineList.size(); i++) {
            cout << i + 1 << ". " << medicineList[i] << endl;
        }
    }

    string getMedicine(int choice) {
        if (choice >= 1 && choice <= medicineList.size()) {
            return medicineList[choice - 1];
        }
        return "None";
    }
};

class Patient {
public:
    string name;
    string id;
    string password;

    string appointmentDoctor;
    string healthIssue;
    string prescription;
    string medicine;
    string dosage;

    Patient() {}

    Patient(string n, string i, string p) {
        name = n;
        id = i;
        password = p;

        appointmentDoctor = "None";
        healthIssue = "None";
        prescription = "None";
        medicine = "None";
        dosage = "None";
    }
};
class Patients : public Login, public Medicine {
private:
    vector<Patient> patientRecords;

public:
    Patients() {
        loadPatients();
    }

    void loadPatients() {
        ifstream file("patients.txt");

        Patient p;

        while (file >> p.name >> p.id >> p.password
                    >> p.appointmentDoctor
                    >> p.healthIssue
                    >> p.prescription
                    >> p.medicine
                    >> p.dosage) {

            patientRecords.push_back(p);
        }

        file.close();
    }

    void saveAllPatients() {
        ofstream file("patients.txt");

        for (auto p : patientRecords) {
            file << p.name << " "
                 << p.id << " "
                 << p.password << " "
                 << p.appointmentDoctor << " "
                 << p.healthIssue << " "
                 << p.prescription << " "
                 << p.medicine << " "
                 << p.dosage << endl;
        }

        file.close();
    }


    void newPatient() {
        string name, id, pass;

        cout << "\n===== New Patient Registration =====\n";

        cout << "Enter Name: ";
        cin >> name;

        cout << "Create ID: ";
        cin >> id;

        cout << "Create Password: ";
        cin >> pass;

        Patient newP(name, id, pass);

        patientRecords.push_back(newP);
        saveAllPatients();

        cout << "\nPatient Registered Successfully!\n";
    }
    void takeAppointment(string patientId) {
        int choice;
        string selectedDoctor;

        cout << "\n===== Take Appointment =====\n";
        cout << "1. Doctor 1 (doc101)\n";
        cout << "2. Doctor 2 (doc102)\n";
        cout << "Choose Doctor: ";
        cin >> choice;

        if (choice == 1)
            selectedDoctor = "doc101";
        else if (choice == 2)
            selectedDoctor = "doc102";
        else {
            cout << "\nInvalid Choice!\n";
            return;
        }

        for (auto &p : patientRecords) {
            if (p.id == patientId) {
                p.appointmentDoctor = selectedDoctor;
                break;
            }
        }

        saveAllPatients();

        cout << "\nAppointment booked successfully!\n";
    }
    void oldPatient() {
        string id, pass;
        bool found = false;

        cout << "\n===== Patient Login =====\n";

        cout << "Enter ID: ";
        cin >> id;

        cout << "Enter Password: ";
        cin >> pass;

        for (auto &p : patientRecords) {
            if (p.id == id && p.password == pass) {
                found = true;

                cout << "\nWelcome " << p.name << "!\n";

                cout << "\nPrescription : " << p.prescription << endl;
                cout << "Medicine     : " << p.medicine << endl;
                cout << "Dosage       : " << p.dosage << endl;

                int ch;
                cout << "\n1. Take Appointment\n";
                cout << "2. Exit\n";
                cout << "Enter Choice: ";
                cin >> ch;

                if (ch == 1) {
                    takeAppointment(id);
                }

                break;
            }
        }

        if (!found) {
            cout << "\nInvalid Login!\n";
        }
    }

    void doctorCheckup(string doctorId) {
        bool found = false;

        for (auto &p : patientRecords) {
            if (p.appointmentDoctor == doctorId) {
                found = true;

                cout << "\n==============================\n";
                cout << "Current Patient: " << p.name << endl;
                cout << "Patient ID     : " << p.id << endl;

                cout << "\nWrite Health Issue: ";
                cin >> p.healthIssue;

                cout << "Write Prescription: ";
                cin >> p.prescription;

                showMedicines();

                int medChoice;
                cout << "\nSelect Medicine: ";
                cin >> medChoice;

                p.medicine = getMedicine(medChoice);

                cout << "Enter Dosage (example: 2times/day): ";
                cin >> p.dosage;

                p.appointmentDoctor = "Completed";

                saveAllPatients();

                cout << "\nPrescription Saved Successfully!\n";

                int next;
                cout << "\n1. Next Patient\n";
                cout << "2. Doctor Signout\n";
                cout << "Enter Choice: ";
                cin >> next;

                if (next == 2) {
                    return;
                }
            }
        }

        if (!found) {
            cout << "\nNo pending appointments for this doctor.\n";
        }
    }

    void patientPanel() {
        int choice;

        cout << "\n===== Patient Section =====\n";
        cout << "1. Old Patient Login\n";
        cout << "2. New Patient Signup\n";
        cout << "Enter Choice: ";
        cin >> choice;

        if (choice == 1)
            oldPatient();
        else if (choice == 2)
            newPatient();
        else
            cout << "\nInvalid Choice!\n";
    }
};
class Doctors : public Login {
public:
    void doctorPanel(Patients &p) {
        string loggedDoctor;

        if (doctorLoginCheck(loggedDoctor)) {
            cout << "\n===== Doctor Panel =====\n";
            cout << "Welcome " << loggedDoctor << endl;

            p.doctorCheckup(loggedDoctor);
        }
    }
};
int main() {
    Patients p;
    Doctors d;

    int choice;

    cout << "\n===== HOSPITAL MANAGEMENT SYSTEM =====\n";
    cout << "1. Doctor Login\n";
    cout << "2. Patient Section\n";
    cout << "Enter Choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            d.doctorPanel(p);
            break;

        case 2:
            p.patientPanel();
            break;

        default:
            cout << "\nInvalid Choice!\n";
    }

    return 0;
}