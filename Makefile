


PROJECT_NAME_SNAKE_CASE=dr_runner



# here are the directories of the projects
# LIBS_ROOT=E:
LIBS_ROOT=/Users/markoates/Repos
ALLEGRO_DIR=$(LIBS_ROOT)/allegro5/build
ALLEGRO_FLARE_DIR=$(LIBS_ROOT)/allegro_flare
GOOGLE_TEST_DIR=$(LIBS_ROOT)/googletest
GOOGLE_TEST_LIB_DIR=$(GOOGLE_TEST_DIR)/build/googlemock/gtest
GOOGLE_TEST_INCLUDE_DIR=$(GOOGLE_TEST_DIR)/googletest/include


# this is the directory of the project (it's auto_generated)
PROJECT_DIR=$(LIBS_ROOT)/$(PROJECT_NAME_SNAKE_CASE)


# these are the names of the libs you are linking
ALLEGRO_FLARE_LIB=allegro_flare-0.8.9wip
ALLEGRO_LIBS=-lallegro_color -lallegro_font -lallegro_ttf -lallegro_dialog -lallegro_audio -lallegro_acodec -lallegro_primitives -lallegro_image -lallegro_main -lallegro
ALLEGRO_LIBS_FOR_TESTS=-lallegro_color -lallegro_font -lallegro_ttf -lallegro_dialog -lallegro_audio -lallegro_acodec -lallegro_primitives -lallegro_image -lallegro_main -lallegro
OPENGL_LIB=-framework OpenGL
# OPENGL_LIB=-lopengl32
# OPENGL_LIB=-lGL
GOOGLE_TEST_LIBS=-lgtest


.PHONY: all clean main fresh



SOURCES := $(shell find src -name '*.cpp')
OBJECTS := $(SOURCES:src/%.cpp=obj/%.o)

TEST_SOURCES := $(shell find tests -name '*.cpp')
TESTS := $(TEST_SOURCES:tests/%.cpp=bin/tests/%)



bin/$(PROJECT_NAME_SNAKE_CASE): programs/$(PROJECT_NAME_SNAKE_CASE).cpp $(OBJECTS)
	@printf "compiling program \e[1m\e[36m$<\033[0m..."
	g++ -std=gnu++11 -Wall -Wuninitialized -Weffc++ $(OBJECTS) $< -o $@ -l$(ALLEGRO_FLARE_LIB) $(ALLEGRO_LIBS) -L$(ALLEGRO_FLARE_DIR)/lib -L$(ALLEGRO_DIR)/lib $(OPENGL_LIB) -I$(ALLEGRO_FLARE_DIR)/include -I$(ALLEGRO_DIR)/include -I./include
	@echo "done. Executable at \033[1m\033[32m$@\033[0m"



obj/%.o: src/%.cpp
	@mkdir -p $(@D)
	@printf "compiling object for \e[1m\e[34m$<\033[0m..."
	@g++ -c -std=gnu++11 -Wall -Wuninitialized -Weffc++ $< -o $@ -I$(ALLEGRO_FLARE_DIR)/include -I$(ALLEGRO_DIR)/include -I./include
	@echo "done. object at \033[1m\033[32m$@\033[0m"



tests: $(TESTS)



run_tests: tests
	find bin/tests -type f -exec {} \;



run_match_tests:
	@echo "usage: make run_match_tests word_youre_trying_to_match"
	$(eval matches := $(filter-out $@,$(MAKECMDGOALS))) # see https://stackoverflow.com/a/6273809/6072362
	$(eval matching_test_filenames := $(shell find ./tests | grep cpp | grep $(matches)))
	$(eval filenames_with_path_subst := $(patsubst ./%, bin/%, $(matching_test_filenames)))
	$(eval matching_binary_filenames := $(patsubst %.cpp, %, $(filenames_with_path_subst)))
	-rm $(matching_binary_filenames)
	make $(matching_binary_filenames)
	find $(matching_binary_filenames) -type f -exec {} \;



bin/tests/%: tests/%.cpp $(OBJECTS)
	@mkdir -p $(@D)
	@printf "compiling test \e[1m\e[36m$<\033[0m..."
	@g++ -std=gnu++11 -Wall -Wuninitialized -Weffc++ $(OBJECTS) $< -o $@ -l$(ALLEGRO_FLARE_LIB) $(ALLEGRO_LIBS_FOR_TESTS) $(GOOGLE_TEST_LIBS) -L$(ALLEGRO_FLARE_DIR)/lib -L$(ALLEGRO_DIR)/lib $(OPENGL_LIB) -I$(ALLEGRO_FLARE_DIR)/include -I$(ALLEGRO_DIR)/include -I./include -I$(GOOGLE_TEST_INCLUDE_DIR) -L$(GOOGLE_TEST_LIB_DIR)
	@echo "done. Executable at \033[1m\033[32m$@\033[0m"



clean:
	-rm -rdf obj/
	-rm -rdf bin/tests/
	-rm bin/$(PROJECT_NAME_SNAKE_CASE)



fresh:
	make clean; make -j8; make run_tests -j8


