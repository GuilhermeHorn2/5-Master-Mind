#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>


std::vector<int> calc_score2(std::string solution,std::string guess);
std::vector<int> calc_score(std::string solution,std::string guess);
int main()
{
	 /* ?\n;||(or) e &&(and)*/

	std::vector<int> v = calc_score2("RGBY","GGRR");
	std::cout << v[0] << '\n';
	std::cout << v[1] << '\n';

	std::vector<int> v = calc_score("RGBY","GGRR");
	std::cout << v[0] << '\n';
	std::cout << v[1] << '\n';


	return 0;
}

std::vector<int> calc_score(std::string solution,std::string guess){

	//v[0] -> hits ; v[1] -> pseudo-hits
	std::vector<int> v = {0,0};

	bool hit[] = {false,false,false,false};
	std::map<char,bool> has_point;
	has_point.insert(std::pair<char,bool>('R',false));
	has_point.insert(std::pair<char,bool>('Y',false));
	has_point.insert(std::pair<char,bool>('G',false));
	has_point.insert(std::pair<char,bool>('B',false));
	std::map<char,bool> has_color;
	has_point.insert(std::pair<char,bool>('R',false));
	has_point.insert(std::pair<char,bool>('Y',false));
	has_point.insert(std::pair<char,bool>('G',false));
	has_point.insert(std::pair<char,bool>('B',false));

	for(int i = 0;i < 3;i++){
		if(solution[i] == guess[i]){
			v[0]++;
			hit[i] = true;
			has_point.insert(std::pair<char,bool>(solution[i],true));
		}
		else{
			has_color.insert(std::pair<char,bool>(solution[i],true));
		}
	}

	for(int i = 0;i < 3;i++){

		if(!hit[i]){

			if(!has_point[guess[i]] && has_color[guess[i]]){
				v[1]++;
				std::cout << guess[i] << '\n';
				has_point.insert(std::pair<char,bool>(guess[i],true));
			}

		}

	}
	return v;

}

std::vector<int> calc_score2(std::string solution,std::string guess){

	//v[0] -> hits ; v[1] -> pseudo-hits
	std::vector<int> v = {0,0};

	bool hit[] = {false,false,false,false};//if the spot has a hit or no
	int quant_color[] = {0,0,0,0};//red,yellow,green,blue
	bool has_point[] = {false,false,false,false};//if the color has a hit os a pseudo hit
	for(int i = 0;i < 3;i++){
		if(solution[i] == guess[i]){
			v[0]++;
			hit[i] = true;
			if(solution[i] == 'R'){
				has_point[0] = true;
			}
			if(solution[i] == 'Y'){
				has_point[1] = true;
			}
			if(solution[i] == 'G'){
				has_point[2] = true;
			}
			if(solution[i] == 'B'){
				has_point[3] = true;
			}
		}
		if(solution[i] == 'R'){
			quant_color[0]++;
		}
		if(solution[i] == 'Y'){
			quant_color[1]++;
		}
		if(solution[i] == 'G'){
			quant_color[2]++;
		}
		if(solution[i] == 'B'){
			quant_color[3]++;
		}
	}

	for(int i = 0;i < 3;i++){

		if(!hit[i]){
			if(guess[i] == 'R' && quant_color[0] > 0 && !has_point[0]){
				v[1]++;
				has_point[0] = true;
			}
			if(guess[i] == 'Y' && quant_color[1] > 0 && !has_point[1]){
				v[1]++;
				has_point[1] = true;
			}
			if(guess[i] == 'G' && quant_color[2] > 0 && !has_point[2]){
				v[1]++;
				has_point[2] = true;
			}
			if(guess[i] == 'B' && quant_color[3] > 0 && !has_point[3]){
				v[1]++;
				has_point[3] = true;
			}
		}

	}


	return v;

}







