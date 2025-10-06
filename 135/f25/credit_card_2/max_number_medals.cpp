//File name: /Users/laptopuser/Documents/courses_macbook_pro/cs135/f25/project2_credit_card_II/doc/../code/section_6_6_2d_array_medals/max_number_medals.cpp

//code link: https://onlinegdb.com/QtmcJBfre

#include <iostream>
#include <string>
#include <fstream> //std::ifstream

//Suppose medals_original.csv has the following contents,
//Country,Gold,Silver,Bronze
//Canada,0,3,0
//Italy,0,0,1
//Germany,0,0,1
//Japan,1,0,0
//Kazakhstan,0,0,1
//Russia,3,1,1
//South Korea,0,1,0
//United States,1,0,1

//Find out the maximum entry in the above file.

//Sample input/output:
//Enter a csv file name with countries and medals (gold, silver, and bronze): medals_original.csv
//maximum number of medals: 3
int main() {
    //Enter a csv file name to read
    std::cout << "Enter a csv file name with countries and medals (gold, silver, and bronze): ";
    std::string fileName;
    std::cin >> fileName;

    //create std::ifstream object fin to read a file with fileName
    std::ifstream fin(fileName);

    //fin cannot open the associated file
    if (fin.fail()) {
       std::cerr << fileName << " cannot be opened" << std::endl;
       exit(1);
    }

    //read the first line, which are column headers without further processing
    std::string columnHeaders;
    getline(fin, columnHeaders);

    //The next line of data contains a country's name, 
    //followed by three integers:
    //numGold, numSilver, and numBronze, respectively.
    std::string country;
    std::string numGoldStr;
    int numGold;
    std::string numSilverStr;
    int numSilver; 
    std::string numBronzeStr;
    int numBronze;

    const int COUNTRY_CAPACITY = 100; //maximum number of countries
    const int MEDALS = 3; //types of medals
    int counts[COUNTRY_CAPACITY][MEDALS];
    std::string countryNames[COUNTRY_CAPACITY];

    int numCountries = 0;

    //Since the file is in CSV format,
    //we need to use 
    //istream& getline(istream& is, string& str, char delim);
    while (getline(fin, country, ',')) { //search for a string before delimiter , save in variable country
        countryNames[numCountries] = country;

        getline(fin, numGoldStr, ','); //number of gold medals is followed by ','
        numGold = stoi(numGoldStr);
        counts[numCountries][0] = numGold;

        getline(fin, numSilverStr, ','); //number of silver medals is followed by ','
        numSilver = stoi(numSilverStr);
        counts[numCountries][1] = numSilver;

        getline(fin, numBronzeStr); //number of bronze medals is followed by '\n', no need to specify delimiter.
        numBronze = stoi(numBronzeStr);
        counts[numCountries][2] = numBronze;

        numCountries++; //number of countries is increased by 1
    }
    fin.close();

    //The medals program is different from credit card project.
    //In medals, there are only three types of medals,
    //while in a credit card, the types of categories can differ from one file to another,
    //so we need to read the file twice in credit card project,
    //In the first round, save the categories in alphabetic order to an array.
    //In the second round, populate the data of two-dimensional array.
    
    int max = counts[0][0];
    for (int i = 0; i < numCountries; i++) { //i is row index
        for (int j = 0; j < MEDALS; j++) { //j is column index, there are MEDALS many columns in each row
            if (counts[i][j] > max) {
               max = counts[i][j];
            }
        }
    }

    std::cout << "maximum number of medals: " << max << std::endl;
    return 0;
}
