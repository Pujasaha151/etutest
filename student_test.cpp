
#include <iostream> 

#include <vector> 

#include <stdexcept> 

#include <gtest/gtest.h> 

using namespace std; 

 

class Student { 

private: 

    string name; 

    int age; 

    vector<int> marks; 

 

public: 

    Student(string studentName, int studentAge) { 

        name = studentName; 

        age = studentAge; 

    } 

 

    void addMarks(int mark) { 

        if (mark < 0 || mark > 100) { 

            throw invalid_argument("Mark should be 0- 100"); 

        } 

        marks.push_back(mark); 

    } 

 

 

    char grade() { 

        if (marks.empty()) { 

            throw runtime_error("No marks available to calculate grade"); 

        } 

 

        double avg = 0; 

        for (int mark : marks) { 

            avg += mark; 

        } 

        avg /= marks.size(); 

 

        if (avg >= 80) return 'A'; 

        if (avg >= 75) return 'B'; 

        if (avg >= 70) return 'C'; 

        if (avg >= 65) return 'D'; 

        return 'F'; 

    } 

}; 

 

// Test cases 

TEST(StudentTest, EmptyStudentThrowsError) { 

    Student s("Marzuka", 22); 

    EXPECT_THROW(s.grade(), runtime_error); 

} 

TEST(AddmarksWorks, AddMarks) { 

    Student s("Anamika", 23); 

    s.addMarks(75); 

    s.addMarks(90); 

    s.addMarks(70); 

    EXPECT_NO_THROW(s.grade()); 

} 
  

TEST(AddmarksWorks, AddsMarks) { 

    Student s("Test", 25); 

    s.addMarks(60); 

    s.addMarks(75); 

 

    EXPECT_EQ(s.grade(), 'D');  // manual checking 

    s.addMarks(80);    // add more 

 

    EXPECT_EQ(s.grade(), 'C');  // after adding 80,  grade 'C' 

} 

 

TEST(AddmarksWorks, AddMarksInvalidInput) { 

    Student s("Test", 22); 

    EXPECT_THROW(s.addMarks(-5), invalid_argument); 

    EXPECT_THROW(s.addMarks(105), invalid_argument); 

} 

 

TEST(GradeTest, Grade_A) { 

    Student s("Etu", 21); 

    s.addMarks(95); 

    s.addMarks(85); 

    s.addMarks(90); 

    EXPECT_EQ(s.grade(), 'A');  // grade A test 

} 

 


TEST(GradeTest, Grade_C) { 

    Student s("Ali", 23); 

    s.addMarks(70); 

    s.addMarks(72); 

    s.addMarks(75); 

    EXPECT_EQ(s.grade(), 'C'); // grade C test 

} 

 
TEST(GradeTest, Grade_D) { 

    Student s("Nadia", 20); 

    s.addMarks(67); 

    s.addMarks(72); 

    s.addMarks(70); 

    EXPECT_EQ(s.grade(), 'D'); // grade D test 

} 


 

TEST(GradeTest, Grade_F) { 

    Student s("Hasan", 22); 

    s.addMarks(50); 

    s.addMarks(55); 

    s.addMarks(58); 

    EXPECT_EQ(s.grade(), 'F'); // grade F test 

} 

int main(int argc, char** argv) { 

    testing::InitGoogleTest(&argc, argv); 

    return RUN_ALL_TESTS(); 

}