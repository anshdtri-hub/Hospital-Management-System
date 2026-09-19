# Hospital Management System (C++)

A console-based hospital management system written in C++ with object-oriented programming. Doctors and patients have separate workflows: patients sign up, log in and book appointments, and doctors see their pending patients and write prescriptions.

## Features
- Patient signup and login
- Appointment booking with a doctor
- Doctor login with a list of pending appointments
- Doctors record the health issue, prescription, medicine (chosen from a list) and dosage
- Patients can view their prescription, medicine and dosage after logging in
- Records are saved to `patients.txt`, which is created automatically when the first patient signs up, and loaded again at startup

## Design
- `Login` holds doctor credentials and checks logins
- `Medicine` holds the list of medicines
- `Patient` is one patient record
- `Patients` inherits from `Login` and `Medicine` and manages all records and file saving
- `Doctors` inherits from `Login` and runs the doctor panel
- Uses the STL (`vector`, `map`) and file streams

## How to run
```
g++ App2.cpp -o App2
./App2
```
On Windows, run `App2` (or `App2.exe`) instead of `./App2`.

## Known limitations
- Passwords are stored as plain text in `patients.txt`
- Text with spaces (such as a prescription) is not saved safely, because records are read one word at a time
- Only two doctors, set in the source code

## Planned improvements
- Hash passwords
- Store data in a database or a safer file format
- Validate user input
