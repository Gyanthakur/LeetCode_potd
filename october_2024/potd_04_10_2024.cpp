//  2491. Divide players into teams of equal skills
// You are given a positive integer array skill of even length n where skill[i] denotes the skill of the ith player. Divide the players into n / 2 teams of size 2 such that the total skill of each team is equal.

// The chemistry of a team is equal to the product of the skills of the players on that team.

// Return the sum of the chemistry of all the teams, or return -1 if there is no way to divide the players into teams such that the total skill of each team is equal.

class Solution {
public:
    long long dividePlayers(vector<int>& skills) {
        int numPlayers = skills.size();
        int totalSkills = 0;
        vector<int> skillCount(1001, 0);

        // Sum up total skill points and track frequency of each skill level
        for (int s : skills) {
            totalSkills += s;
            skillCount[s]++;
        }

        // Check if total skill points can be evenly divided among teams
        if (totalSkills % (numPlayers / 2) != 0) {
            return -1;
        }

        int teamSkillTarget = totalSkills / (numPlayers / 2);
        long long teamChemistry = 0;

        // Form teams and calculate chemistry
        for (int s : skills) {
            int pairSkill = teamSkillTarget - s;

            // Ensure valid team formation
            if (skillCount[pairSkill] == 0) {
                return -1;
            }

            teamChemistry += (long long)s * (long long)pairSkill;
            skillCount[pairSkill]--;
        }

        // Return half the chemistry since each pair is counted twice
        return teamChemistry / 2;
    }
};
