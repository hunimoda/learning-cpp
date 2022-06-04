#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

void DrawHorizontalLine() {
  std::cout << std::setw(23) << std::setfill('-') << ""
            << std::setfill(' ') << std::endl;
}

int CheckResponse(std::string answer, std::string response) {
  int correct = 0;
  for (size_t i = 0; i < answer.size(); i++)
    if (answer[i] == response[i]) correct++;
  return correct;
}

template <typename T>
void PrintRow(std::string field1, int width1, T field2, int width2) {
  std::cout << std::fixed << std::setprecision(1);
  std::cout << std::setw(width1) << std::left << field1
            << std::setw(width2) << std::right << field2 << std::endl;
}

int main() {
  // Open file response.txt
  std::ifstream grade_file("responses.txt");
  if (!grade_file) {
    std::cerr << "Could not open file" << std::endl;
    return 1;
  }

  // Get answer from first line
  std::string answer;
  grade_file >> answer;

  // Print top bar
  PrintRow("Student", 15, "Score", 8);
  DrawHorizontalLine();

  // Display each student's score
  std::string name, response;
  int total_score = 0, num_of_students = 0;
  while (grade_file >> name >> response) {
    int score = CheckResponse(answer, response);
    total_score += score, num_of_students++;
    PrintRow(name, 15, score, 8);
  }
  DrawHorizontalLine();

  // Show average score
  if (num_of_students) {
    PrintRow("Average Score", 15,
            static_cast<double>(total_score) / num_of_students, 8);
  }

  // Close file & exit
  grade_file.close();
  return 0;
}