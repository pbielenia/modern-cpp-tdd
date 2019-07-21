SoundexTest: SoundexTest.cpp Soundex.cpp CharUtil.cpp StringUtil.cpp
	g++ -Wall $^ -o $@ -lgmock -lpthread

.PHONY: clean
clean:
	rm SoundexTest