#include "product.h"
#include <string>
#include <sstream>
#include <iomanip>

std::string product::product_info() {
	std::ostringstream info;
	info << std::fixed << std::setprecision(2) <<
		name << " ($" << price << "): " << description <<
		"\n";

	return info.str();
}
