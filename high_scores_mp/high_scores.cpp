#include "high_scores.hpp"

#include <algorithm>
#include <cstdint>
#include <map>
#include <string>
#include <vector>
#include <utility>

using std::map, std::string, std::pair, std::vector;

namespace arcade {

  std::map<std::string, std::vector<uint32_t>> HighScores::scores() {
    return score_;
}


  std::vector<uint32_t> HighScores::scores(std::string player) {
    return score_[player];
}

void HighScores::add_score(std::string player, uint32_t score)
{

  std::vector<u_int32_t> result = score_.at(player);

  result.push_back(score);

  score_[player] = result;
}

uint32_t HighScores::latest_score(std::string player) const {
  std::vector<u_int32_t> result = score_.at(player);

  return result[result.size() - 1];
}

uint32_t HighScores::personal_best(std::string player) const {
  std::vector<u_int32_t> result = score_.at(player);

  std::sort(result.begin(), result.end(), std::greater<uint32_t>());

  return result[0];
}

std::pair<std::string, uint32_t> HighScores::overall_best() const {
  std::pair<std::string, uint32_t> m;
        return m;
}


std::vector<uint32_t> HighScores::top_three(std::string player) const {
  std::vector<uint32_t> m;
  return m;
}



}  // namespace arcade
