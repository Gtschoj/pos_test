#ifndef HIGH_SCORES_HPP
#define HIGH_SCORES_HPP

#include <cstdint>
#include <map>
#include <string>
#include <vector>
#include <utility>

using std::map, std::string, std::pair, std::vector;

namespace arcade {

  class HighScores {
    public:
      HighScores()=default;
      HighScores(std::map<std::string, std::vector<uint32_t>> score) :
        score_(score) {};
      HighScores(std::vector< std::pair< std::string, uint32_t >> scores) :
        scores_(scores) {};

      std::map< std::string, std::vector< uint32_t>> scores();
      std::vector< uint32_t> scores(std::string player);
      void add_score(std::string player, uint32_t score);
      uint32_t latest_score(std::string player) const;
      uint32_t personal_best(std::string player) const;
      std::pair< std::string, uint32_t> overall_best() const;
      std::vector<uint32_t>top_three(std::string player) const;
      std::vector< std::pair< std::string, uint32_t>> top_three() const;

    private:
      std::map<std::string, std::vector<uint32_t>> score_;
      std::vector< std::pair< std::string, uint32_t >> scores_;
  }; // class HighScores



}  // namespace arcade

#endif  // HIGH_SCORES_HPP
