.PHONY: all configure build test run pack clean

all: configure build

config:
	@echo "🔧 Running configuration with CMake..."
	cmake --preset tetris-debug

build:
	@echo "🏗️  Building binary with Ninja..."
	ninja -C out/build/tetris-debug

test:
	@echo "🧪 Running all tests..."
	ctest --test-dir ./out/build/tetris-debug/tests

test_one:
ifeq ($(TEST_NAME),)
	@echo "❌ Please specify a test name with: make test_one TEST_NAME=<YourTestName>"
else
	@echo "🧪 Running test named '$(TEST_NAME)'..."
	ctest --test-dir ./out/build/tetris-debug/tests -R $(TEST_NAME)
endif

run:
	@echo "🚀 Running the executable..."
	./out/build/tetris-debug/tetris.exe

pack:
	@echo "📦 Packing the build with CPack..."
	cpack --config ./out/build/tetris-debug/CPackConfig.cmake

clean:
	@echo "🧹 Cleaning up build output..."
	rd /s /q out\ || rm -rf out/
