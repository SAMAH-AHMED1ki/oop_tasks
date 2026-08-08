#include <vector>
using namespace std;
#include <sstream>
#include <iostream>
#include <algorithm>
#include<string>
#include<fstream>
fstream file;
class student {
public:
   
    
    string nam;
    vector<int> grd = vector<int>(5);
    void addstudent() {
       
        cout << "        ADD NEW STUDENT       " << endl;
        cout << "Enter Student Name : ";
        cin >> nam;
        file.clear();
        file.seekp(0, ios::end);
        file << nam << " ";
        cout << "Add 5 grades (0 - 100) " << endl;
        for (int j = 0;j < 5;j++)
        {
            cout << "Grade " << j + 1 << " : ";
            cin >> grd[j];
            file << grd[j] << " ";
        }
        file << endl;
        cout << "  Student Added Successfully  " << endl;
    }
};
class compute {
public:
    double calcavg(student* prstd) {
        double avg = 0;
        for (int j = 0;j < 5;j++)
        {

            avg += prstd->grd[j];
        }
        avg /= 5;
        return avg;
    }
    student readstd(string Line) {
        student prstd;
        istringstream ss(Line);
        ss >> prstd.nam;
        for (int i = 0;i < 5;i++) {
            ss >> prstd.grd[i];

        }
        return prstd;
    }
    string status_(double avg) {
        if (avg >= 50) {
            return "Pass";
        }
        else {
            return "Fail";
        }
    }
};
class chara {
public:
    void characters() {
        vector<double> averages;
        averages.clear();
        file.clear();
        file.seekg(0);
        int p = 0, f = 0;
        string Line;
        compute e;
        while (getline(file, Line)) {
            student prstd = e.readstd(Line);
            double y = e.calcavg(&prstd);
            averages.push_back(y);
            if (y >= 50) {

                p++;
            }
            else {

                f++;
            }
        }
        if (!averages.empty()) {
            double high = *max_element(averages.begin(), averages.end());
            double low = *min_element(averages.begin(), averages.end());
            cout << "Passing :" << p << endl;
            cout << "Failing :" << f << endl;
            cout << "Highest average :" << high << endl;
            cout << "Lowest average :" << low << endl;
        }
        else {
            cout << "File is empty !";
        }
    }
};

class print_ {
public:
    void print() {
        compute r;
        file.clear();
        file.seekg(0);
        double aa;
        string Line;
        while (getline(file, Line)) {
            student prstd = r.readstd(Line);
            cout << prstd.nam << endl;
            for (int i = 0;i < 5;i++) {

                cout << prstd.grd[i] << " ";
            }
            cout << endl;
            cout << "Average ";
            aa = r.calcavg(&prstd);
            cout << aa << endl;
            string status = r.status_(aa);
            cout << "status :" << status;

        }
    }
};
        class search_ {
        public:
            void search(string nam) {
                bool found = false;
                string nn = nam;
                file.clear();
                file.seekg(0);
                double aa;
                string Line;
                compute r;
                while (getline(file, Line)) {
                    student prstd = r.readstd(Line);
                    if (nn == prstd.nam) {
                        found = true;
                        cout << "Student found !!";
                        cout << prstd.nam;
                        for (int i = 0;i < 5;i++) {

                            cout << prstd.grd[i] << " ";

                        }

                        cout << "Average ";

                        aa = r.calcavg(&prstd);
                        cout << aa << endl;
                        string status = r.status_(aa);
                        cout << "status :" << status;

                        break;
                    }
                }
                if (!found) {
                    cout << "NOT FOUND " << endl;
                }
            }
        };

        int main()
        {
            file.open("student.txt", ios::out | ios::in );
            if (file.fail()) {
                cout << "Cant open the file";
                file.open("student.txt", ios::out);
                file.close();                       
                file.open("student.txt", ios::in | ios::out);
            }
            cout << "  + -------------------------------------- + " << endl
                << " | STUDENT GRADE MANAGEMENT SYSTEM |" << endl
                << " + -------------------------------------- + " << endl;
            bool flag = true;
            string h;
            while (flag) {
                cout << " 1. Add Student " << endl << " 2. Show All Students " << endl << " 3. Search Student " << endl << " 4. Class Statistics  " << endl << " 5.  Exit " << endl;
                int n;
                cout << "Enter your choice (1-5) : ";
                cin >> n;
                student std;
                search_ sea;
                chara c;
                print_ pp;
                switch (n)
                {
                case 1:

                    std.addstudent();
                    cout << endl << endl;
                    break;
                case 2:
                    pp.print();
                    cout << endl << endl;
                    break;
                case 3:
                    cout << "Enter Student Name : " << endl;
                    cin >> h;
                    sea.search(h);
                    cout << endl << endl;
                    break;
                case 4:
                    c.characters();
                    cout << endl << endl;
                    break;
                case 5:
                    flag = false;
                    break;
                }
            }
        }
