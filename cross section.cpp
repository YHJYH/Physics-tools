//Yuheng Jia 
//This is used to calculate the value of cross section for Zee and Zmumu reactions in 2lep real data set



#include<iostream>



double Zee_cross_section(double N_sel, double Zee,
	double Ztautau, double Zmumu, double Wplus_2lep, double Wminus_2lep, double ttbar_lep) {
	double integral_L{ 10.064 };
	double cross_sec;
	double epsilon;
	double TotExpected_Zee{ 19630128.89 };
	epsilon = Zee / TotExpected_Zee;
	cross_sec = (N_sel - (Zmumu + Ztautau + Wplus_2lep + Wminus_2lep + ttbar_lep)) / (epsilon * integral_L);
	return cross_sec;
}

double Zmumu_cross_section(double N_sel, double Zmumu,
	double Ztautau, double Zee, double Wplus_2lep, double Wminus_2lep, double ttbar_lep) {
	double integral_L{ 10.064 };
	double cross_sec;
	double epsilon;
	double TotExpected_Zmumu{ 19631161.45 };
	epsilon = Zmumu / TotExpected_Zmumu;
	cross_sec = (N_sel - (Zee + Ztautau + Wplus_2lep + Wminus_2lep + ttbar_lep)) / (epsilon * integral_L);
	return cross_sec;
}

double standard_deviation(double e1, double e2, double e3, double e4, double e5, double e6, double e7) {
	double standard_deviation;
	double mean;
	double variance;
	mean = (e1 + e2 + e3 + e4 + e5 + e6 + e7) / 7;
	std::cout << "mean: " << mean << std::endl;
	variance = (pow((e1 - mean), 2) + pow((e2 - mean), 2) + pow((e3 - mean), 2) + pow((e4 - mean), 2) + pow((e5 - mean), 2) + pow((e6 - mean), 2) + pow((e7 - mean), 2)) / 7;
	std::cout << "variance: " << variance << std::endl;
	standard_deviation = sqrt(variance);
	return standard_deviation;
}

int main() 
{
	double N_selected;
	double Ztautau;
	double Wplus_2lep;
	double Wminus_2lep;
	double ttbar_lep;
	double Zee;
	double Zmumu;
	double e1{ 1.93735e6 };
	double e2{ 1.85903e6 };
	double e3{ 1.83702e6 };
	double e4{ 1.8405e6 };
	double e5{ 1.87595e6 };
	double e6{ 1.84242e6 };
	double e7{ 1.86393e6 };

	std::cout << "std: " << standard_deviation(e1, e2, e3, e4, e5, e6, e7) << std::endl;

	//std::cout << (1.92514e6 + 1.86018e6 + 1.84685e6 + 1.8518e6 + 1.87021e6 + 1.84134e6 + 1.8694e6) / 7 << std::endl;
	//std::cout << pow((1.92514e6 - 1.86642e6), 2) + pow((1.86018e6 - 1.86642e6), 2) + pow((1.84685e6 - 1.86642e6), 2) + pow((1.8518e6 - 1.86642e6), 2) + pow((1.87021e6 - 1.86642e6), 2) + pow((1.84134e6 - 1.86642e6), 2) + pow((1.8694e6 - 1.86642e6), 2) << std::endl;
	//std::cout << 4.73596e9 / 7 << std::endl;
	//std::cout << sqrt(6.76566e8) << std::endl;

start:

	std::cout << "N_selected (2lep with selcuts): " << std::endl;
	std::cin >> N_selected;
	std::cout << "Ztautau: " << std::endl;
	std::cin >> Ztautau;
	std::cout << "Wplus_2lep: " << std::endl;
	std::cin >> Wplus_2lep;
	std::cout << "Wminus_2lep: " << std::endl;
	std::cin >> Wminus_2lep;
	std::cout << "ttbar_lep: " << std::endl;
	std::cin >> ttbar_lep;
	std::cout << "Zee: " << std::endl;
	std::cin >> Zee;
	std::cout << "Zmumu: " << std::endl;
	std::cin >> Zmumu;
	std::cout << "The value of cross section is: " <<
		Zmumu_cross_section(N_selected, Zmumu, Ztautau, Zee, Wplus_2lep, Wminus_2lep, ttbar_lep) << " fb" << std::endl;
	goto start;

	return 0;
}
