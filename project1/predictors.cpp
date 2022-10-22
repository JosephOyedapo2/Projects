#include <iostream>
#include <fstream>
#include <vector>
#include "Branch.h"

using namespace std;

int main(int argc, char *argv[]){
    (void)argc;
    Branch b;
	unsigned long addr;
	vector<unsigned long> addrArray;
    string prediction;
    vector<string> predictArr;
    unsigned long target;
    vector<unsigned long> targArr;
   

     ifstream input(argv[1]);
	 ofstream output;
     output.open(argv[2]);
  
   
  
    while(input >> hex >> addr >> prediction >> hex >> target){
  	    addrArray.push_back(addr);
  	    predictArr.push_back(prediction);
  	    targArr.push_back(target);
    }
  
    Branch predict = b.alwaysTaken(predictArr);
    output << predict.predictors << "," << predict.branch << ";" << endl;
    predict = b.alwaysNotTaken(predictArr);
    output << predict.predictors << "," << predict.branch << ";" << endl;
 	vector<int> tableSizes{16, 32, 128, 256, 512, 1024, 2048};

 	for(unsigned int i = 0; i < tableSizes.size() - 1; i++){
 		predict = b.oneBitBimodalPredictor(addrArray, predictArr, tableSizes[i]);
 		output << predict.predictors << "," << predict.branch << "; ";
 	    }
 	predict = b.oneBitBimodalPredictor(addrArray, predictArr, tableSizes[tableSizes.size()-1]);
 	
 	output << predict.predictors << "," << predict.branch << ";" << endl;
 	
 	
 	for(unsigned int i = 0; i < tableSizes.size() - 1; i++){
 		predict = b.twoBitBimodalPredictor(addrArray, predictArr, tableSizes[i]);
 		output << predict.predictors << "," << predict.branch << "; ";
 	    }
 	
 	predict = b.twoBitBimodalPredictor(addrArray, predictArr, tableSizes[tableSizes.size() - 1]);
 	
 	output << predict.predictors << "," << predict.branch << ";" << endl;
 	
 	
 	for(int i = 3; i < 11; i++){
 		predict = b.Gshare(addrArray, predictArr, i);
 		output << predict.predictors << "," << predict.branch << "; ";
 	    }
 	
 	predict = b.Gshare(addrArray, predictArr, 11);
 	
 	output << predict.predictors << "," << predict.branch << ";" << endl;
  
  
    predict = b.tournamentPredictor(addrArray, predictArr);
    output << predict.predictors << "," << predict.branch << ";" << endl;
  
    predict = b.BTB(addrArray, predictArr, targArr);
    output << predict.predictors << "," << predict.branch << ";" << endl;
  
    input.close();
    output.close();

}