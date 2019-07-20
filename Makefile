SoundexTest: SoundexTest.cpp Soundex.cpp
	g++ -Wall $^ -o $@ -lgmock -lpthread

.PHONY: clean
clean:
	rm SoundexTest