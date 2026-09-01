#include <algorithm>
#include <print>
#include <format>
#include <vector>
#include <string>

#include "test-base.h"

namespace tests::heap
{
	struct some_struct
	{
		int value = 0;
		std::string name = "";
		
		explicit operator std::string() const
		{
			return std::format("Value: {}, Name: {}", value, name);
		}
	};
	
	class heap_test : public test_base
	{
	public:
	
		virtual void run() override
		{
			const auto heap_predicate = [](const some_struct& A, const some_struct& B) -> bool
			{
				return A.value > B.value;
			};
			
			{
				items_.push_back({1, "apple"});
				items_.push_back({3, "banana"});
				items_.push_back({2, "grapes"});
				std::print("State of items_ after subsequent push backs without using heap_push:\n");
				print_items();
			}
			
			{
				some_struct mango_item{.value = 0, .name = "mango"};
				std::print("Pushing {}.\n", static_cast<std::string>(mango_item));
				items_.push_back({0, "mango"});
				print_items();
			}
			
			{
				std::print("Performing heap_push.\n");
				std::ranges::push_heap(items_, heap_predicate);
				std::print("State of items_ after heap_push on \"mango\"\n");
				print_items();
			}
			
			{
				std::print("State of items_ after performing heap_pop twice:\n");
				std::ranges::pop_heap(items_, heap_predicate);
				items_.pop_back();
				std::ranges::pop_heap(items_, heap_predicate);
				items_.pop_back();
				print_items();
			}
		}
		
	private:
		
		void print_items()
		{
			for (const some_struct& item : items_)
			{
				std::print("{}\n", static_cast<std::string>(item));
			}
		}
	
	private:
	
		std::vector<some_struct> items_;
	};	
}
