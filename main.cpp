

#include "Database.h"
#include "matplot/axes_objects/histogram.h"
#include <algorithm>
#include <matplot/matplot.h>
#include <string>
#include <vector>
using namespace std;
using namespace matplot;

void heightDistribution(Database *d) {

  vector<string> *heights = new vector<string>();
  vector<double> heightd;
  d->getTable("athletes.csv")->returnColumn(9, heights);
  for (const string &s : *heights) {
    try {
      heightd.push_back(stod(s)); // Try converting the string to double
    } catch (const invalid_argument &e) {
      cerr << "Invalid input: '" << s << "' cannot be converted to double"
           << endl;
    } catch (const out_of_range &e) {
      cerr << "Out of range error: '" << s << "' is too large to be a double"
           << endl;
    }
  }

  // Filter out zero values
  vector<double> filtered_heights;
  copy_if(heightd.begin(), heightd.end(), back_inserter(filtered_heights),
          [](double h) { return h > 0.0; });

  // Create a histogram using Matplot++
  auto h = hist(filtered_heights); // 10 bins for the histogram

  // Add labels and a title
  title("Height Distribution of Athletes");
  xlabel("Height (cm)");
  ylabel("Number of Athletes");

  h->face_color("red");

  // Display the plot
  show();
}
void weightDistribution(Database *d) {
  vector<string> *weights = new vector<string>();
  vector<double> weightd;

  d->getTable("athletes.csv")->returnColumn(10, weights);

  for (const string &s : *weights) {
    try {
      weightd.push_back(stod(s)); // Try converting the string to double
    } catch (const invalid_argument &e) {
      cerr << "Invalid input: '" << s << "' cannot be converted to double"
           << endl;
    } catch (const out_of_range &e) {
      cerr << "Out of range error: '" << s << "' is too large to be a double"
           << endl;
    }
  }
  vector<double> filtered_weights;
  copy_if(weightd.begin(), weightd.end(), back_inserter(filtered_weights),
          [](double h) { return h > 0.0; });


  auto h = hist(filtered_weights); // 10 bins for the histogram

  // Add labels and a title
  title("Weight Distribution of Athletes");
  xlabel("Weight (kg)");
  ylabel("Number of Athletes");

  h->face_color("red");
  show();
}
int main() {

  Database *d = new Database();
  d->loadDatabase("/home/sujat/projects/CSE225-summer24-project/data");
  // heightDistribution(d);
  // d->getTable("athletes.csv")->display();
  weightDistribution(d);
}
