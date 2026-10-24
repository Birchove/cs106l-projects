#include "spellcheck.h"

#include <algorithm>
#include <cctype>
#include <iostream>
#include <iterator>
#include <numeric>
#include <ranges>
#include <set>
#include <string>
#include <vector>

template <typename Iterator, typename UnaryPred>
std::vector<Iterator> find_all(Iterator begin, Iterator end, UnaryPred pred);

Corpus tokenize(std::string& source) {
  auto all_space_its = find_all(source.begin(), source.end(), [](char c){return std::isspace(c);});
  Corpus result;

  // 注意transform的此重载中, 要求两个迭代器等长, 所以不会传入last2
  std::transform(all_space_its.begin(), --all_space_its.end(), ++all_space_its.begin(), std::inserter(result, result.end()), 
    [& source] (auto x, auto y) {return Token(source, x, y);}
);
  std::erase_if(result, [](const Token& t){return t.content.empty();});

  return result;

}

std::set<Misspelling> spellcheck(const Corpus& source, const Dictionary& dictionary) {
  auto miss_spelling_distance_one = source 
                                  | std::views::filter(
    [&dictionary](const Token& token) {return !(dictionary.contains(token.content));}
                                  )
                                  | std::views::transform(
                                    [&dictionary](const Token& token) {
                                      auto view = dictionary | std::views::filter(
                                        [&token](const std::string& word){return levenshtein(word, token.content) == 1;}
                                      );
                                      std::set<std::string> suggestions(view.begin(), view.end());
                                      return Misspelling {.token=token, .suggestions=suggestions};
                                      
                                    }
                                  )
                                  | std::views::filter(
                                    [](const Misspelling& mp){return !mp.suggestions.empty();}
                                  )
                                  | std::ranges::to<std::set<Misspelling>>();
  return miss_spelling_distance_one;

};

/* Helper methods */

#include "utils.cpp"