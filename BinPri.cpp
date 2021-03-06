#include <iostream>
#include <algorithm>
#include <cmath>
#include <utility>

int main()
{
	double s0, u, d, r, t, i, k;
	std::cout<< "Enter  s0 "; std::cin >> s0;  // value for sotck
	std::cout << "Enter  u "; std::cin >> u;	 // value for up
	std::cout << "Enter  d "; std::cin >> d;	 // value for down
	std::cout << "Enter  r "; std::cin >> r;	 // value for risk free
	std::cout << "Enter  t "; std::cin >> t;	 // value for time
	std::cout << "Enter  i "; std::cin >> i;	 // value for node
	std::cout << "Enter  k "; std::cin >> k;	 // value for node
	bool to_price = true;

	if (s0 <= 0.0 || u <= -1.0 || d <= -1.0 || r <= -1.0 || i > t) //checking for legal values
	{
		std::cout << "Illegal data range" << std::endl;
		to_price = false;
		return 1;
	}
	if (r >= u || r <= d ) //checking for arbitrage
	{
		to_price = false;
		std::cout << "Arbitrage!" << std::endl;
		return 1;
	}
	if (to_price == true)
	{
		std::cout << "No Arbitrage checked, proceeding to price!" << std::endl;
		// Computing the Q probability
		double q = (r - d) / (u - d);
		double stock = s0 * pow(1 + u, t) * pow(1 + d, t - i);
		std::cout << "The S(t,i) is \n" << stock << std::endl;
		double price = std::max(stock - k, 0.0);
		std::cout << "The price is \n" << price << std::endl;
		return 0;
	}
}