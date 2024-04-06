#include <iostream>
#include <string>
#include <fstream> 
#include <algorithm>
using namespace std;

struct district{
   string name;
   string type;
   int num_resident;
   int power;
   bool has_power;
   int num_technician;
   string technicians[];
};

bool compareNumResidents(const district &x, const district &y){
   return x.num_resident < y.num_resident;
}

void load(string fname, district districts[], int &num, int &power) {
   string techName;
   district districtInfo;

   ifstream fin(fname);

   if (!fin.is_open()) {
      cout << "File not Found" << endl;
      exit(1);
   }

   fin >> power;
   fin >> num;
   fin.ignore();

   for (int i = 0; i < num; i++) {
      getline(fin, districtInfo.name);
      fin >> districtInfo.type;
      fin >> districtInfo.num_resident;
      fin >> districtInfo.power;
      fin >> districtInfo.has_power;
      fin >> districtInfo.num_technician;
      fin.ignore();
      
      districtInfo.technicians.clear();
      for (int j = 0; j < districtInfo.num_technician; j++) {
         getline(fin, techName);
         districtInfo.technicians.push_back(techName);
      }
      districts[i] = districtInfo;
   }
   sort(districts, districts + num, compareNumResidents);

   fin.close();

    
}



void save(string fname, district districts[], int num, int power){
   
   ofstream fout(fname);
   
   if(!fout.is_open()){
      cout << "File not Found" << endl;
      exit(1);
   }
   
   fout << power << endl;
   fout << num << endl;
   
   for(int i = 0 ; i < num ; i ++){
      fout << districts[i].name << endl;
      fout << districts[i].type << endl;
      fout << districts[i].num_resident << endl;
      fout << districts[i].power << endl;
      fout << districts[i].has_power << endl;
      fout << districts[i].num_technician << endl;
      for (const auto &tech : districts[i].technicians) {
            fout << tech << endl;
        }
   }
   fout.close();
}


void print_all(district districts[], int num, int total_power_supply){
   int total_power_demand = 0;
   for(int k = 0 ; k < num ; k++){
      if (districts[k].has_power) {
         total_power_demand += districts[k].power;
      }
   }
   
   cout << "The current power supply is " << total_power_supply << "MW." << endl;
   for( int i = 0 ; i < num ; i++){
      cout << districts[i].name << endl;
      cout << "District type: " << districts[i].type << endl;
      cout << "Number of residents: " << districts[i].num_resident << endl;
      if (districts[i].has_power) {
         cout << "Power use: " <<  districts[i].power << "MW" << endl;
      } else {
         cout << "Power use: 0MW" << endl;
      }

      cout << "Has power: " <<  districts[i].has_power << endl;
      
      if (!districts[i].technicians.empty()) {
            cout << "Technicians: ";
            for (size_t j = 0; j < districts[i].technicians.size(); j++) {
               if (j == districts[i].technicians.size() - 1) {
                    cout << districts[i].technicians[j];
                }
                else{
                cout << districts[i].technicians[j] << ", ";
               }
            }
         cout << endl;   
      }  
      cout << "---" << endl;
   }
   
   if(total_power_supply < total_power_demand){
      cout << "Critical Error! The current power supply of " << total_power_supply << "MW is insufficient to supply " << total_power_demand << "MW of power demand. Please shut off one or more districts." << endl;
      cout << "---" << endl;
   }
}

void assign_technician(string tech_name, string district_name, district districts[], int num_district){
   bool districtFound = false;
   for (int i = 0; i < num_district; ++i) {
      if (districts[i].name == district_name) {
         districts[i].technicians.push_back(tech_name);
         districts[i].num_technician += 1;
         districtFound = true;
         cout << "Technician assigned!" << endl;
         break; 
      }
   }
   if(!districtFound){
      cout << "Error! The district with that name doesn't exist." << endl;
   }
}


void cut_power(const string& district_name, district districts[], int num_districts) {
    for (int i = 0; i < num_districts; ++i) {
        if (districts[i].name == district_name) {
            districts[i].has_power = false;
            cout << "The district's power has been successfully turned off." << endl;
            return;
        }
    }
    cout << "Error! The district with that name doesn't exist." << endl;
}

void restore_power(const string& district_name, district districts[], int num_districts) {
    for (int i = 0; i < num_districts; ++i) {
        if (districts[i].name == district_name) {
            districts[i].has_power = true;
            cout << "The district's power has been successfully turned back on." << endl;
            return;
        }
    }
    cout << "Error! The district with that name doesn't exist." << endl;
}


int main(){
   const int SPACE = 200;
   district districts[SPACE];
   int num_districts = 0;
   int total_power_supply = 0;
   string filename;
   int choice;
   
   cout << "Please enter the name of the file to load:" << endl;
   cin >> filename;
   
   load(filename, districts, num_districts, total_power_supply);
   save(filename,districts, num_districts, total_power_supply);
   print_all(districts, num_districts, total_power_supply);
   
   while(true){
      cout << "Main Menu" << endl;
      cout << "1- Status" << endl;
      cout << "2- Set Power Supply" << endl;
      cout << "3- Shutoff Power" << endl;
      cout << "4- Restore Power" << endl;
      cout << "5- Assign Technician" << endl;
      cout << "6- Save" << endl;
      cout << "7- Load" << endl;
      cout << "8- Exit" << endl;

      cout << "Please enter your choice:" << endl;
      cin >> choice;
      cin.ignore(); 
       
      switch(choice){
         case 1:
            print_all(districts, num_districts, total_power_supply);
         break;
         
         case 2:
            cout << "Enter the updated power supply in megawatts:" << endl;
            cin >> total_power_supply;
         break;
         
         case 3:{
            string distName;
            cout << "Enter the name of the district:" << endl;
            getline(cin, distName);
            cut_power(distName, districts, num_districts);
         break;
         }
         case 4:{
            string distName;
            cout << "Enter the name of the district:" << endl;
            getline(cin, distName);
            restore_power(distName, districts, num_districts);
         break;
         }
         case 5:{
            string techName;
            string distName;
            cout << "Enter the name of the technician:" << endl;
            getline(cin, techName);
            cout << "Enter the name of the district to assign them to:" << endl;
            getline(cin, distName);
            
            assign_technician(techName, distName, districts, num_districts);
         break;
         }
         case 6:{
            string fname;
            cout << "Enter the file name to save to:" << endl;
            getline(cin, fname);
            
            save(fname, districts, num_districts, total_power_supply);
         break;
         }
         case 7:{
            string fname;
            cout << "Enter the file name to load from:" << endl;
            getline(cin, fname);
            
            load(fname, districts, num_districts, total_power_supply);
         break;
         }
         case 8:
            exit(0);
         break;
         
         default:
            cout << "Invalid option!" << endl;
         break;
      }
         
         
         
      
   }
   
   
   return 0;
}