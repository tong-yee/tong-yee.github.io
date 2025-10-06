//File name: /Users/laptopuser/Documents/courses_macbook_pro/cs135/f25/project2_credit_card_II/doc/../code/section_6_6_2d_array_medals/medals_to_csv.cpp

//code link: https://onlinegdb.com/8rU18e-SS5

#include <iostream>
#include <string>
#include <fstream> //std::ifstream, std::ofstream

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

//Need to provide medals_original.csv to run this program.
//Sample input/output:
//Enter a csv file name with countries and medals (gold, silver, and bronze): medals_original.csv
//Enter an output file name: medals_tally.csv

//Generate medals_tally.csv with the following contents.
//Country,Gold,Silver,Bronze,Medal Count By Country
//Canada,0,3,0,3
//Italy,0,0,1,1
//Germany,0,0,1,1
//Japan,1,0,0,1
//Kazakhstan,0,0,1,1
//Russia,3,1,1,5
//South Korea,0,1,0,1
//United States,1,0,1,2
//Medals Totals For All Countries,5,5,5,15
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
    
    std::cout << "Enter an output file name: ";
    std::string outputFileName;
    std::cin >> outputFileName;

    std::ofstream fout(outputFileName);
    if (fout.fail()) {
       std::cerr << outputFileName << " cannot be opened." << std::endl;
       exit(2);
    }

    //print "Country,Gold,Silver,Bronze,Medal Count By Country\n" to fout
    //This is column header of the output CSV file
    fout << "Country,";
    std::string medal_names[] = {"Gold", "Silver", "Bronze"};
    for (int j = 0; j < MEDALS; j++) {
        fout << medal_names[j] << ',';
    }
    fout << "Medal Count By Country\n";

    int medalCountByCountry; //Medal Count by Country
    int total = 0;
    for (int i = 0; i < numCountries; i++) { //i is row index
        fout << countryNames[i] << ','; //',' can be written as ","
        medalCountByCountry = 0;
        for (int j = 0; j < MEDALS; j++) { //j is column index, there are MEDALS many columns in each row
            fout << counts[i][j] << ",";
            medalCountByCountry += counts[i][j];
        }
        fout << medalCountByCountry << "\n"; //finish the row
        total += medalCountByCountry;
    }

    //Calculate gold-, silver-, and bronze- totals for all countries
    int medalTotalAllCountries[MEDALS];
    for (int j = 0; j < MEDALS; j++) {
        medalTotalAllCountries[j] = 0;

        for (int i = 0; i < numCountries; i++) {
            medalTotalAllCountries[j] += counts[i][j];
        }
    }

    fout << "Medals Totals For All Countries,"; //no entry before the first entry
    for (int j = 0; j < MEDALS; j++) {
        fout << medalTotalAllCountries[j] << ",";
    }
    fout << total; //no need to have a new line, end of file   
   
    fout.close();
    return 0;
}
