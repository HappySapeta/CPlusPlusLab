#pragma once

namespace tests
{
	class test_base
	{
	public:
		virtual ~test_base() = default;
		virtual void run() = 0;
	};
}
