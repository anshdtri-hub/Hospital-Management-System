#include <bits/stdc++.h>
using namespace std;

class MedicalApp {
protected:
    
    string d1 = "AnshTripathi";
    string d2 = "Rythm";
    string d3 = "Venkantesh";

    int p1 = 1234, p2 = 2026, p3 = 2027;


    string patientName;
    string patientDOB;
    string patientLoginID;
    int patientPass;
    bool patientRegistered = false;

    
    char userType;
    int pass;
    string loginID;

public:
    void askUserType() {
        cout << "Select Login Type" << endl;
        cout << "1. Doctor Login" << endl;
        cout << "2. Patient Login" << endl;
        cout << "Enter d for Doctor or p for Patient: ";
        cin >> userType;
    }

    void doctorLogin() {
        cout << endl << "--- Doctor Login ---" << endl;
        cout << "Enter Login ID: ";
        cin >> loginID;

        cout << "Enter Password: ";
        cin >> pass;

        if (loginID == d1 && pass == p1) {
            cout << "LOGIN SUCCESSFUL\n";
            cout << "Doctor Logged In: Dr. Ansh Tripathi\n";
        }
        else if (loginID == d2 && pass == p2) {
            cout << "LOGIN SUCCESSFUL\n";
            cout << "Doctor Logged In: Dr. Rythm\n";
        }
        else if (loginID == d3 && pass == p3) {
            cout << "LOGIN SUCCESSFUL\n";
            cout << "Doctor Logged In: Dr. Venkantesh\n";
        }
        else {
            cout << "Invalid Doctor Login\n";
        }
    }

    void appointment() {
        char choice;
        cout << "\nDo you want an appointment? [y/n]: ";
        cin >> choice;

        if (choice == 'y' || choice == 'Y') {
            int docChoice;
            cout << "Choose Doctor:\n";
            cout << "1. Dr. Ansh Tripathi\n";
            cout << "2. Dr. Rythm\n";
            cout << "3. Dr. Venkantesh\n";
            cout << "Enter choice (1/2/3): ";
            cin >> docChoice;

            switch (docChoice) {
                case 1:
                    cout << "Appointment fixed with Dr. Ansh Tripathi\n";
                    break;
                case 2:
                    cout << "Appointment fixed with Dr. Rythm\n";
                    break;
                case 3:
                    cout << "Appointment fixed with Dr. Venkantesh\n";
                    break;
                default:
                    cout << "Invalid doctor choice\n";
            }
        }
        else {
            cout << "No appointment booked.\n";
        }
    }

    void savePatientToFile() {
        ofstream file("patient.txt");
        file << patientName << endl;
        file << patientDOB << endl;
        file << patientLoginID << endl;
        file << patientPass << endl;
        file.close();
    }

    bool loadPatientFromFile() {
        ifstream file("patient.txt");
        if (!file) {
            return false;
        }

        getline(file, patientName);
        getline(file, patientDOB);
        getline(file, patientLoginID);
        file >> patientPass;
        file.close();
        patientRegistered = true;
        return true;
    }

    void newPatient() {
        cout << endl << "--- New Patient Registration ---" << endl;

        cout << "Enter Name: ";
        cin >> patientName;

        cout << "Enter DOB: ";
        cin >> patientDOB;

        cout << "Create Login ID: ";
        cin >> patientLoginID;

        cout << "Create Password: ";
        cin >> patientPass;

        patientRegistered = true;
        savePatientToFile();

        cout << "Patient Registered Successfully and Saved for Future Use!" << endl;
        appointment();
    }

    void oldPatient() {
        cout << endl << "--- Old Patient Login ---" << endl;}]}


        if (!loadPatientFromFile()) {
            cout << "No old patient record found. Please register first.\n";
            return;
        }

        string enteredID;
        int enteredPass;

        cout << "Enter Login ID: ";
        cin >> enteredID;

        cout << "Enter Password: ";
        cin >> enteredPass;

        if (enteredID == patientLoginID && enteredPass == patientPass) {
            cout << "LOGIN SUCCESSFUL\n";
            cout << "Welcome back, " << patientName << "\n";
            appointment();
        }
        else {
            char option;
            cout << "Wrong Login ID or Password!\n";
            cout << "Do you want to create a new ID? [y/n]: ";
            cin >> option;

            if (option == 'y' || option == 'Y') {
                newPatient();
            }
            else {
                cout << "Try again later.\n";
            }
        }
    }

    void patientSection() {
        char patientType;

        cout << "\nAre you a New or Old Patient? [n/o]: ";
        cin >> patientType;

        switch (patientType) {
            case 'n':
            case 'N':
                newPatient();
                break;

            case 'o':
            case 'O':
                oldPatient();
                break;

            default:
                cout << "Invalid Choice\n";
        }
    }

    void start() {
        askUserType();

        switch (userType) {
            case 'd':
            case 'D':
                doctorLogin();
                break;

            case 'p':
            case 'P':
                patientSection();
                break;

            default:
                cout << "Invalid User Type\n";
        }
    }
};

int main() {
    MedicalApp obj;
    obj.start();
    return 0;
}
