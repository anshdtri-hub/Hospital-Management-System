#include<bits/stdc++.h>
using namespace std;
class medicalapp{
    protected:
    string appointmentPatient;
   string appointmentDoctor;

void saveAppointmentToFile() {
    ofstream file("appointment.txt");
    file << appointmentPatient << endl;
    file << appointmentDoctor << endl;
    file.close();
}

void loadAppointmentFromFile() {
    ifstream file("appointment.txt");
    if (file) {
        file >> appointmentPatient;
        file >> appointmentDoctor;
    }
    file.close();
 }
    string ploginID;
    int patp;
    string pat1="sai";
    string pat2="ayush";
    int  totaldoc=3;
    string d1="AnshTripathi";
    string d2="Rythm";
    string d3="venkatesh";
    int p1=1234,p2=2026,p3=2027;
    int pat1p=5677,pat2p=6777;
    int DOB;
    string name;
    int newpass;
    char y;
    char x;
    int pass;
    string loginID;
    public:
    void ask(){
        cout<<"Are you a doctor or patient[d/p]"<<endl;
        cin>>x;

    }
   
    void login() {
        switch (x) {
            case 'd':
                cout << "Enter Login ID: ";
                cin >> loginID;

                cout << "Enter Password: ";
                cin >> pass;

                if (loginID == d1 && pass == p1) {
                    cout << "LOGIN SUCCESSFUL" << endl;
                    cout << "Doctor Logged In: Dr. Ansh Tripathi" << endl;
                        loadAppointmentFromFile();
                     if (appointmentDoctor == d1) {
                  cout << "Today's Appointment Patient: " 
                    << appointmentPatient << endl;
                 }
                }
                else if (loginID == d2 && pass == p2) {
                    cout << "LOGIN SUCCESSFUL" << endl;
                    cout << "Doctor Logged In: Dr. Rythm" << endl;
                        loadAppointmentFromFile();
                     if (appointmentDoctor == d2) {
                      cout << "Today's Appointment Patient: " 
                      << appointmentPatient << endl;
                     }
                }
                else if (loginID == d3 && pass == p3) {
                    cout << "LOGIN SUCCESSFUL" << endl;
                    cout << "Doctor Logged In: Dr. Venkatesh" << endl;
                        loadAppointmentFromFile();
                     if (appointmentDoctor == d3) {
                      cout << "Today's Appointment Patient: " 
                      << appointmentPatient << endl;
                     }
                }
                else {
                    cout << "INVALID LOGIN ID OR PASSWORD" << endl;
                }
                break;

            case 'p':
                cout << "Patient Login Section" << endl;
                cout<<"new patient or old patient [N/O]"<<endl;
                cin>>y;
                switch (y){
                    case 'N':
                  cout << "NAME: ";
                    cin >> name;

                  cout << "DATE OF BIRTH [DateMonthYear]: ";
                 cin >> DOB;

                    cout << "Create Login ID: ";
                  cin >> ploginID;

                  cout << "Create Password: ";
                   cin >> newpass;

                    cout << "Patient Registered Successfully" << endl;
                    cout << "Do you want an appointment? [y/n]" << endl;
                 char app;
                 cin >> app;

                  if (app == 'y' || app == 'Y') {
                 int docChoice;

                    cout << "Choose Doctor" << endl;
                   cout << "1. Dr. Ansh Tripathi" << endl;
                 cout << "2. Dr. Rythm" << endl;
                  cout << "3. Dr. Venkantesh" << endl;
                    cout << "Enter choice: ";
                   cin >> docChoice;

                   switch (docChoice) {
                   case 1:
                    appointmentPatient = name;
                  appointmentDoctor = d1;

                 cout << "Appointment fixed with Dr. Ansh Tripathi" << endl;
                 saveAppointmentToFile();
                   break;

                  case 2:
                   appointmentPatient = name;
                 appointmentDoctor = d2;

                   cout << "Appointment fixed with Dr. Rythm" << endl;
                   saveAppointmentToFile();
                  break;

                  case 3:
                   appointmentPatient = name;
                 appointmentDoctor = d3;

                  cout << "Appointment fixed with Dr. Venkantesh" << endl;
                  saveAppointmentToFile();
                  break;

                 default:
                  cout << "Invalid doctor choice" << endl;
                 }}
                 else {
                  cout << "No appointment booked" << endl;
                    }
                 break;
                    case 'O':
                    cout<<"login id:";
                    cin>>ploginID;
                    cout<<"pass";
                    cin>>patp;
                    if( ploginID == pat1&& patp==pat1p||ploginID == pat2&& patp==pat2p){
                        cout<<"LOGIN SUCCESSFULL";
                    
                    cout << "Do you want an appointment? [y/n]" << endl;
                   char app;
                 cin >> app;

                 if (app == 'y' || app == 'Y') {
                 int docChoice;

                  cout << "Choose Doctor" << endl;
                  cout << "1. Dr. Ansh Tripathi" << endl;
                   cout << "2. Dr. Rythm" << endl;
                    cout << "3. Dr. Venkantesh" << endl;
                   cout << "Enter choice: ";
                   cin >> docChoice;

                  switch (docChoice) {
                   case 1:
                 appointmentPatient = name;
                  appointmentDoctor = d1;

                   cout << "Appointment fixed with Dr. Ansh Tripathi" << endl;
                 break;

                 case 2:
                  appointmentPatient = name;
                  appointmentDoctor = d2;

                   cout << "Appointment fixed with Dr. Rythm" << endl;
                  break;

                  case 3:
                  appointmentPatient = name;
                 appointmentDoctor = d3;

                cout << "Appointment fixed with Dr. Venkatesh" << endl;
                 break;

                  default:
                    cout << "Invalid doctor choice" << endl; }} 
                  else {
                   cout << "No appointment booked" << endl;}}
                    else{
                        cout<<"wrong id pass";
                    }
                 }
                break;

            default:
                cout << "Invalid Choice" << endl;
                
        }
    }
};
int main() {
    medicalapp obj;

    obj.ask();
    obj.login();

    return 0;
}