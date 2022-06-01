#include <iostream>
#include <memory>
#include <vector>

using std::unique_ptr;
using std::shared_ptr;
using std::vector;

class Test {
 public:
  Test() : data_(0) {
    std::cout << "\tTest constructor(" << data_ << ")" << std::endl;
  }
  Test(int data) : data_(data) {
    std::cout << "\tTest constructor(" << data_ << ")" << std::endl;
  }
  ~Test() { std::cout << "\tTest destructor(" << data_ << ")" << std::endl; }
  int GetData() const { return data_; }

 private:
  int data_;
};

auto Make();
void Fill(vector<shared_ptr<Test>> &vec, int num);
void Display(const vector<shared_ptr<Test>> &vec);

auto Make() {
  return std::make_unique<vector<shared_ptr<Test>>>();
}

void Fill(vector<shared_ptr<Test>> &vec, int num) {
  for (int i = 1; i <= num; i++) {
    int data_point;
    std::cout << "Enter data point [" << i << "] : ";
    std::cin >> data_point;
    vec.push_back(std::make_shared<Test>(data_point));
  }
}

void Display(const vector<shared_ptr<Test>> &vec) {
  std::cout << "----- Output data -------------------" << std::endl;
  for (const auto &test_ptr : vec)
    std::cout << test_ptr->GetData() << std::endl;
}

int main() {
  unique_ptr<vector<shared_ptr<Test>>> vec_ptr;
  vec_ptr = Make();

  std::cout << "How many data points do you want to enter: ";
  int num_of_data_points;
  std::cin >> num_of_data_points;

  Fill(*vec_ptr, num_of_data_points);
  Display(*vec_ptr);

  return 0;
}
