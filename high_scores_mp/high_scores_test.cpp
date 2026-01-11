#include "high_scores.hpp"

#include <cstdint>
#include <map>
#include <string>
#include <vector>
#include <utility>

#include <catch2/catch_test_macros.hpp>

using std::map, std::string, std::pair, std::vector;


TEST_CASE("High Scores") {
  const arcade::HighScores chs{{
    {"Chris", 10},
    {"Chris", 90},
    {"Pat", 30},
    {"Pat", 50},
    {"Chris", 30},
    {"Pat", 20},
    {"Pat", 70},
  }};
  arcade::HighScores hs{chs};

  SECTION("retrieve_scores") {
    const map<string, vector<uint32_t>> expected{
      {"Chris", {10, 90, 30}},
      {"Pat", {30, 50, 20, 70}},
    };
    REQUIRE(chs.scores() == expected);
  }

  SECTION("retrieve_player_scores") {
    const std::vector<uint32_t> expected_pat{30, 50, 20, 70};
    std::vector<uint32_t> expected_chris{10, 90, 30};
    REQUIRE(chs.scores("Pat") == expected_pat);
    REQUIRE(chs.scores("Chris") == expected_chris);
    uint32_t new_chris{85};
    hs.add_score("Chris", new_chris);
    expected_chris.push_back(new_chris);
    REQUIRE(hs.scores("Chris") == expected_chris);
  }

  SECTION("add_and_retrieve_scores") {
    const map<string, vector<uint32_t>> expected{
      {"Chris", {10, 90, 30}},
      {"Pat", {30, 50, 20, 70}}};
    arcade::HighScores scores{};
    scores.add_score("Chris", 10);
    scores.add_score("Chris", 90);
    scores.add_score("Pat", 30);
    scores.add_score("Pat", 50);
    scores.add_score("Chris", 30);
    scores.add_score("Pat", 20);
    scores.add_score("Pat", 70);
    REQUIRE(scores.scores() == expected);
  }

  SECTION("additional_scores") {
    const map<string, vector<uint32_t>> expected{
      {"Anne", {80}},
      {"Chris", {10, 90, 30}},
      {"Pat", {30, 50, 20, 70, 75}},
    };
    hs.add_score("Anne", 80);
    hs.add_score("Pat", 75);
    REQUIRE(hs.scores() == expected);
  }

  SECTION("latest_score_by_player") {
    uint32_t expected_chris{30};
    uint32_t expected_pat{70};
    uint32_t expected_pat_new{100};
    REQUIRE(chs.latest_score("Chris") == expected_chris);
    REQUIRE(chs.latest_score("Pat") == expected_pat);
    hs.add_score("Pat", expected_pat_new);
    REQUIRE(hs.latest_score("Pat") == expected_pat_new);
  }

  SECTION("personal_best") {
    uint32_t expected_chris{90};
    uint32_t expected_pat{70};
    REQUIRE(chs.personal_best("Chris") == expected_chris);
    REQUIRE(chs.personal_best("Pat") == expected_pat);

    expected_chris = 100;
    expected_pat = 110;
    hs.add_score("Chris", expected_chris);
    hs.add_score("Pat", expected_pat);
    REQUIRE(hs.personal_best("Chris") == expected_chris);
    REQUIRE(hs.personal_best("Pat") == expected_pat);
  }

  SECTION("overall_best") {
    pair<string, uint32_t> expected{"Chris", 90};
    REQUIRE(chs.overall_best() == expected);

    expected = {"Pat", 100};
    hs.add_score("Pat", expected.second);
    REQUIRE(hs.overall_best() == expected);
    expected = {"Chris", 110};
    hs.add_score("Chris", expected.second);
    REQUIRE(hs.overall_best() == expected);
  }

  SECTION("personal_top_three") {
    std::vector<uint32_t> expected_chris{90, 30, 10};
    std::vector<uint32_t> expected_pat{70, 50, 30};
    REQUIRE(chs.top_three("Chris") == expected_chris);
    REQUIRE(chs.top_three("Pat") == expected_pat);
    hs.add_score("Chris", 10);
    hs.add_score("Pat", 20);
    REQUIRE(hs.top_three("Chris") == expected_chris);
    REQUIRE(hs.top_three("Pat") == expected_pat);
  }

  SECTION("personal_top_three_changed") {
    std::vector<uint32_t> expected_chris{90, 50, 30};
    std::vector<uint32_t> expected_pat{90, 70, 50};
    hs.add_score("Chris", 50);
    hs.add_score("Pat", 90);
    REQUIRE(hs.top_three("Chris") == expected_chris);
    REQUIRE(hs.top_three("Pat") == expected_pat);
  }

  SECTION("personal_top_three_tie") {
    const std::vector<uint32_t> expected_chris{90, 90, 30};
    const std::vector<uint32_t> expected_pat{70, 50, 50};
    hs.add_score("Chris", 90);
    hs.add_score("Pat", 50);
    REQUIRE(hs.top_three("Chris") == expected_chris);
    REQUIRE(hs.top_three("Pat") == expected_pat);
  }

  SECTION("personal_top_three_fewer_values") {
    std::vector<uint32_t> expected{70};
    hs.add_score("Anne", 70);
    REQUIRE(hs.top_three("Anne") == expected);
    expected.push_back(60);
    hs.add_score("Anne", 60);
    REQUIRE(hs.top_three("Anne") == expected);
  }

  SECTION("latest_score_after_personal_best",
          "Test if latest_score is still valid after calling personal_best") {
    uint32_t expected_chris{30};
    hs.personal_best("Chris");
    REQUIRE(hs.latest_score("Chris") == expected_chris);
    uint32_t expected_pat{70};
    hs.personal_best("Pat");
    REQUIRE(hs.latest_score("Pat") == expected_pat);
  }

  SECTION("latest_score_after_personal_top_three",
          "Test if latest_score is still valid after calling top_three") {
    u_int32_t expected_chris{30};
    hs.top_three("Chris");
    REQUIRE(hs.latest_score("Chris") == expected_chris);
    uint32_t expected_pat{70};
    hs.top_three("Pat");
    REQUIRE(hs.latest_score("Pat") == expected_pat);
  }

  SECTION("top_three") {
    vector<pair<string, uint32_t>> expected{
      {"Chris", 90},
      {"Pat", 70},
      {"Pat", 50}};
    REQUIRE(chs.top_three() == expected);
  }

  SECTION("top_three_changed") {
    hs.add_score("Anne", 100);
    vector<pair<string, uint32_t>> expected{
      {"Anne", 100},
      {"Chris", 90},
      {"Pat", 70}};
    REQUIRE(hs.top_three() == expected);
  }

  SECTION("top_three_tie",
          "sorting of tie is left the author (name or time of result)") {
    hs.add_score("Anne", 90);
    vector<uint32_t> expected{90, 90, 70};
    vector<uint32_t> actual{};
    for (auto p: hs.top_three()) {
      actual.push_back(p.second);
    }
    REQUIRE(actual == expected);
  }
}
