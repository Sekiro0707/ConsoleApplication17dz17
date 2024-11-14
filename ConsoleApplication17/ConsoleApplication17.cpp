#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

class Disp_kod {
public:
    string compnam;
    string owner;
    string phone;
    string add;
    string actunt;

    Disp_kod(string name, string owner, string phone, string add, string actunt)
        : compnam(name), owner(owner), phone(phone), add(add), actunt(actunt) {}
};

class Directory {
private:
    vector<Disp_kod> entries;

    void loadFile() {
        ifstream file("directory.txt");
        if (!file) return;

        string name, owner, phone, add, actunt;
        while (getline(file, name) && getline(file, owner) &&
            getline(file, phone) && getline(file, add) &&
            getline(file, actunt)) {
            entries.push_back(Disp_kod(name, owner, phone, add, actunt));
        }
        file.close();
    }

    void save_fort() {
        ofstream file("directory.txt");
        for (const auto& entry : entries) {
            file << entry.compnam << endl;
            file << entry.owner << endl;
            file << entry.phone << endl;
            file << entry.add << endl;
            file << entry.actunt << endl;
        }
        file.close();
    }

public:
    Directory() {
        loadFile();
    }

    ~Directory() {
        save_fort();
    }

    void addfornt(const Disp_kod& entry) {
        entries.push_back(entry);
        save_fort();
    }

    void gunthlfn(const string& name) const {
        for (const auto& entry : entries) {
            if (entry.compnam == name) {
                displent(entry);
            }
        }
    }

    void spuntkool(const string& owner) const {
        for (const auto& entry : entries) {
            if (entry.owner == owner) {
                displent(entry);
            }
        }
    }

    void bokum(const string& phone) const {
        for (const auto& entry : entries) {
            if (entry.phone == phone) {
                displent(entry);
            }
        }
    }

    void platz(const string& activity) const {
        for (const auto& entry : entries) {
            if (entry.actunt == activity) {
                displent(entry);
            }
        }
    }

    void dipall() const {
        for (const auto& entry : entries) {
            displent(entry);
        }
    }

private:
    void displent(const Disp_kod& entry) const {
        cout << "Назва фірми: " << entry.compnam << endl;
        cout << "Власник: " << entry.owner << endl;
        cout << "Телефон: " << entry.phone << endl;
        cout << "Адреса: " << entry.add << endl;
        cout << "Рід діяльності: " << entry.actunt << endl;
    }
};

int main() {
    Directory directory;
    directory.addfornt(Disp_kod("TechCorp", "Іван Іванов", "123456789", "м. Київ", "ІТ послуги"));
    cout << "Пошук за назвою фірми 'TechCorp':" << endl;
    directory.gunthlfn("TechCorp");
    cout << "\nВсі записи в довіднику:" << endl;
    directory.dipall();

    return 0;
}
