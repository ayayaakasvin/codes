#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

double returnable_gpa_point (vector <int> points_of_subjects, int credit) {
    double sum_of_subject_gpa = accumulate(points_of_subjects.begin(), points_of_subjects.end(), 0);
    if (points_of_subjects[0] + points_of_subjects[1] < 30 or points_of_subjects[2] < 20)
    {
        return 0;
    }
    else if (sum_of_subject_gpa > 50)
    {   
        if (sum_of_subject_gpa >= 95)
        {
            return 4.0;
        }
        return 1 + (((sum_of_subject_gpa - 50) / 5.0) * 1.0 / 3.0);
    }
}

vector <double> solution (vector< vector <int>> gpa, vector <int> credits) {
    vector <double> result;
    for (int i = 0; i < gpa.size(); i++)
    {
        double gpa_of_subject = returnable_gpa_point(gpa[i], credits[i]);
        result.push_back(gpa_of_subject * credits[i]);
    }
    
    return result;
}

int main () {
    int l;
    cin >> l;
    vector <vector <int>> points_of_students;
    vector <int> credits(l);

    for (int i = 0; i < l; i++) 
    {
        vector<int> temp_gpa_vector;
        for (int j = 0; j < 3; j++) 
        {
            int temp_points_varia;
            cin >> temp_points_varia;
            temp_gpa_vector.push_back(temp_points_varia);
        }
        cin >> credits[i];
        points_of_students.push_back(temp_gpa_vector);
    }
    
    double gpa_point_final = 0;
    int credits_sum = accumulate(credits.begin(), credits.end(), 0);
    vector <double> answer_array = solution(points_of_students, credits);
    for (int i = 0; i < answer_array.size(); i++)
    {
        gpa_point_final += answer_array[i] / credits_sum;
    }
    
    cout << gpa_point_final;
    return 0;
}