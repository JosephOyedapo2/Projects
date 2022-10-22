#include <iostream>
#include <vector>
#include <bitset>
#include <math.h>

using namespace std;

class Branch{
    public:
    int predictors;
    int branch;
    Branch(){
 	predictors = 0;
 	branch = 0;
    }

Branch alwaysTaken(vector <string> branchArr){
    Branch prediction;
    for(unsigned int i = 0; i < branchArr.size(); i++){
		if(branchArr[i] == "T"){
			prediction.predictors++;
		}
		prediction.branch++;
	}
	return prediction;
}
Branch alwaysNotTaken(vector <string> branchArr){
	Branch prediction;
	for(unsigned int i = 0; i < branchArr.size(); i++){
		if(branchArr[i] == "NT"){
			prediction.predictors++;
		}
		prediction.branch++;
	}
	return prediction;
}
Branch oneBitBimodalPredictor(vector <unsigned long> addArr, vector<string> branchArr, int size){
	Branch prediction;
	vector<string> bitSize(size, "T");
	
	for (unsigned int i = 0; i < addArr.size(); i++){
		int indexBit = addArr[i]%size;
		
		if (bitSize[indexBit] == branchArr[i]){
			prediction.predictors++;
		}
		else {
			if (branchArr[i] == "T"){
				bitSize[indexBit] = "T";
			}
			else{
				bitSize[indexBit] = "NT";
			}
		}
		prediction.branch++;
	}
	
	return prediction;
}
Branch twoBitBimodalPredictor(vector <unsigned long> addArr, vector<string> branchArr, int size){
	Branch prediction;
	vector<int> bitSize(size, 3);
	for (unsigned int i = 0; i < addArr.size(); i++){
		int indexBit = addArr[i]%size;
		if(branchArr[i] == "T"){
			if(bitSize[indexBit] == 2 || bitSize[indexBit] == 3){
				prediction.predictors++;
			}
			if(bitSize[indexBit] < 3){
				bitSize[indexBit]++;
			}
		}
		else{
			if(bitSize[indexBit] == 0 || bitSize[indexBit] == 1){
				prediction.predictors++;
			}
			if(bitSize[indexBit] > 0){
				bitSize[indexBit]--;
			}
		}
		prediction.branch++;
	}
	return prediction;
}
Branch Gshare(vector <unsigned long> addArr, vector<string> branchArr, int bitSize){
	Branch prediction;
	unsigned long size = (int) pow(2,bitSize) - 1;
	unsigned int GHR = 0;
	
	vector<int> table(2048 ,3);
	
	for (unsigned int i = 0; i < addArr.size(); i++){
		bool shift = false;
		int index = (addArr[i] ^ (GHR & size))%2048;
		if(branchArr[i] == "T"){
			if(table[index] == 2 || table[index] == 3){
				prediction.predictors++;
			}
			if(table[index] < 3){
				table[index]++;
			}
			shift = true;
		}
		else{
			if(table[index] == 0 || table[index] == 1){
				prediction.predictors++;
			}
			if(table[index] > 0){
				table[index]--;
			}
		}
		GHR = GHR << 1;
		if(shift){
			GHR = GHR | 1;
		}
	}
	prediction.branch = addArr.size();
	return prediction;
}
Branch tournamentPredictor(vector <unsigned long> addArr, vector<string> branchArr){
	Branch prediction;
	vector<int> tableGshare(2048, 3);
	vector<int> tableBimodal(2048, 3);
	vector<int> selectorTable(2048 ,0);
	unsigned long size = (int) pow(2,11) - 1;
	unsigned int GHR = 0;
	
	
	for (unsigned int i = 0; i < addArr.size(); i++){
		bool bimodalPrediction = false;
		int bimodalIndex = addArr[i]%2048;
		
		if(branchArr[i] == "T"){
			if(tableBimodal[bimodalIndex] == 2 || tableBimodal[bimodalIndex] == 3){
				bimodalPrediction = true;
			}
			if(tableBimodal[bimodalIndex] != 3){
				tableBimodal[bimodalIndex]++;
			}
		}
		else{
			if(tableBimodal[bimodalIndex] == 0 || tableBimodal[bimodalIndex] == 1){
				bimodalPrediction = true;
			}
			if(tableBimodal[bimodalIndex] != 0){
				tableBimodal[bimodalIndex]--;
			}
		}
		
		
		bool shift = false;
		
		bool GsharePrediction = false;
		int GshareIndex = (addArr[i] ^ (GHR & size))%2048;
		
		if(branchArr[i] == "T"){
			if(tableGshare[GshareIndex] == 2 || tableGshare[GshareIndex] ==3){
				GsharePrediction = true;
				
			}
			if(tableGshare[GshareIndex] != 3){
				tableGshare[GshareIndex]++;
			}
			shift = true;
		}
		else{
			if(tableGshare[GshareIndex] == 0 || tableGshare[GshareIndex] ==1){
				GsharePrediction = true;
				
			}
			if(tableGshare[GshareIndex] != 0){
				tableGshare[GshareIndex]--;
			}
		}
		
		GHR = GHR << 1;
		if(shift == true){
			GHR = GHR | 1;
		}
		
		int select = selectorTable[bimodalIndex];
		
		if(GsharePrediction == bimodalPrediction){
			if(GsharePrediction == true){
				prediction.predictors++;
			}
		}
		else{
			if(select == 2 || select == 3){
				if(bimodalPrediction == true){
					prediction.predictors++;
					if (select == 2){
						selectorTable[bimodalIndex]++;
					}
				}
				else{
					if (select > 0) {
						selectorTable[bimodalIndex]--;
					}
				}
			}
			else{
				if(GsharePrediction == true){
					prediction.predictors++;
					if(select == 1){
						selectorTable[bimodalIndex]--;
					}
				}
				else{
					if (select < 3) {
						selectorTable[bimodalIndex]++;
					}
				}
			}
		}
	}
	prediction.branch = addArr.size();
	return prediction;
}
Branch BTB(vector<unsigned long> addArr, vector<string> branchArr, vector<unsigned long> btbArr){
	Branch prediction;
	vector<string> bimodalArr(512, "T");
	vector<unsigned long> targetArr(512, 0);
	for(unsigned int i = 0; i < addArr.size(); i++){
		int index = addArr[i]%512;
		if(bimodalArr[index] == "T"){
			prediction.branch++;
			if(targetArr[index] == btbArr[i]){
				prediction.predictors++;
			}
			
		}
		if(branchArr[i] == "T"){
			targetArr[index] = btbArr[i];
		}
		if(bimodalArr[index] != branchArr[i]){
			bimodalArr[index] = branchArr[i];
		}
	}
	return prediction;		
}
};
