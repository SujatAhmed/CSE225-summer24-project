// Graph.cpp
#include "Graphs.h"
#include <algorithm>
#include <iostream>
#include <stdexcept>

using namespace matplot;

void Graph::heightDistribution(Database *d) {
  std::vector<std::string> *heights = new std::vector<std::string>();
  std::vector<double> heightd;
  d->getTable("athletes.csv")->returnColumn(9, heights);

  for (const std::string &s : *heights) {
    try {
      heightd.push_back(std::stod(s));
    } catch (const std::invalid_argument &e) {
      std::cerr << "Invalid input: '" << s << "' cannot be converted to double"
                << std::endl;
    } catch (const std::out_of_range &e) {
      std::cerr << "Out of range error: '" << s
                << "' is too large to be a double" << std::endl;
    }
  }

  delete heights; // Clean up dynamically allocated memory

  std::vector<double> filtered_heights;
  std::copy_if(heightd.begin(), heightd.end(),
               std::back_inserter(filtered_heights),
               [](double h) { return h > 0.0; });

  auto h = hist(filtered_heights); // 10 bins for the histogram

  title("Height Distribution of Athletes");
  xlabel("Height (cm)");
  ylabel("Number of Athletes");

  h->face_color("red");

  show();
}

void Graph::weightDistribution(Database *d) {
  std::vector<std::string> *weights = new std::vector<std::string>();
  std::vector<double> weightd;

  d->getTable("athletes.csv")->returnColumn(10, weights);

  for (const std::string &s : *weights) {
    try {
      weightd.push_back(std::stod(s));
    } catch (const std::invalid_argument &e) {
      std::cerr << "Invalid input: '" << s << "' cannot be converted to double"
                << std::endl;
    } catch (const std::out_of_range &e) {
      std::cerr << "Out of range error: '" << s
                << "' is too large to be a double" << std::endl;
    }
  }

  delete weights; // Clean up dynamically allocated memory

  std::vector<double> filtered_weights;
  std::copy_if(weightd.begin(), weightd.end(),
               std::back_inserter(filtered_weights),
               [](double h) { return h > 0.0; });

  auto h = hist(filtered_weights); // 10 bins for the histogram

  title("Weight Distribution of Athletes");
  xlabel("Weight (kg)");
  ylabel("Number of Athletes");

  h->face_color("red");

  show();
}
