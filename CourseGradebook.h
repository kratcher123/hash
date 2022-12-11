#ifndef COURSEGRADEBOOK_H
#define COURSEGRADEBOOK_H

#include <map>
#include <algorithm>
#include "Gradebook.h"

class CourseGradebook : public Gradebook {
protected:
	// Your code here
	std::map<int, std::unordered_map<std::string, double>> ids;
	std::map <std::string, std::unordered_map<int, double>> scores;

public:
	virtual ~CourseGradebook() {
		// Your code here, if needed

	}

	std::unordered_map<int, double> GetAssignmentScores(
		std::string assignmentName) override {
		// Your code here (remove placeholder line below)
		return scores[assignmentName];
	}

	double GetScore(std::string assignmentName, int studentID) override {
		// Your code here (remove placeholder line below)
		try {
			return ids.at(studentID).at(assignmentName);

		}
		catch (std::out_of_range ex) {
			return NAN;
		}
	}

	std::vector<std::string> GetSortedAssignmentNames() override {
		// Your code here (remove placeholder line below)
		std::vector<std::string> keys;
		keys.reserve(scores.size());


		for (auto v : scores) {
			keys.push_back(v.first);
		}
		return keys;
	}

	// GetSortedStudentIDs() returns a vector with all distinct student IDs,
	// sorted in ascending order.
	std::vector<int> GetSortedStudentIDs() override {
		// Your code here (remove placeholder line below)
		std::vector<int> keys;
		keys.reserve(ids.size());


		for (auto v : ids) {
			keys.push_back(v.first);
		}
		return keys;
	}

	// GetStudentScores() gets all scores that exist in the gradebook for the
	// student whose ID equals the studentID parameter. Scores are returned as
	// an unordered_map that maps an assignment name to the student's
	// corresponding score for that assignment.
	std::unordered_map<std::string, double> GetStudentScores(
		int studentID) override {
		return ids[studentID];
	}

	void SetScore(std::string assignmentName, int studentID, double score) override {
		// Your code here
		auto& entry = ids[studentID];
		entry[assignmentName] = score;

		std::unordered_map<int, double>& enter = scores[assignmentName];
		enter[studentID] = score;

	}
};

#endif