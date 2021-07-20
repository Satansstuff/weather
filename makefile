all:	main.cpp
	@echo "building.."
	@g++ main.cpp -std=c++20 -o uweather
	@echo "Done!"
install:
	@echo "building.."
	@sudo g++ main.cpp -std=c++20 -o /usr/local/bin/uweather
	@echo "Done!"
uninstall:
	@echo "Uninstalling uweather"
	@sudo rm /usr/local/bin/uweather
	@echo "Done"
clean:
	@rm -f uweather

