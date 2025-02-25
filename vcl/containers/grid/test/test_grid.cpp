#include "../../../base/base.hpp"
#include "../grid.hpp"


#include <iostream>

namespace vcl_test {

	void text_grid_2D()
	{
		{
			vcl::grid_2D<int> a;
			a.resize(2, 2);
			assert_vcl_no_msg(is_equal(a.dimension, vcl::size_t2{ 2,2 }));
			assert_vcl_no_msg(type_str(a)=="grid_2D<int>");

			a(0, 0) = 1; a(0, 1) = 2;
			a(1, 0) = 3; a(1, 1) = 4;
			assert_vcl_no_msg(a[0] == 1);
			assert_vcl_no_msg(a[1] == 3);
			assert_vcl_no_msg(a[2] == 2);
			assert_vcl_no_msg(a[3] == 4);

			vcl::grid_2D<int> b(2,2);
			b(0, 0) = 0; b(0, 1) = -2;
			b(1, 0) = -1; b(1, 1) = 1;

			vcl::grid_2D<int> c(2,2);
			c(0, 0) = 1; c(0, 1) = 0;
			c(1, 0) = 2; c(1, 1) = 5;
			assert_vcl_no_msg(is_equal(a + b, c));
		}

		{
			vcl::grid_2D<int> a;
			a.resize(3, 3);
			assert_vcl_no_msg(is_equal(a.dimension, vcl::size_t2{ 3,3 }));
			assert_vcl_no_msg(type_str(a) == "grid_2D<int>");

			a(0, 0) = 1; a(0, 1) = 2; a(0, 2) = 3;
			a(1, 0) = 4; a(1, 1) = 5; a(1, 2) = 6;
			a(2, 0) = 7; a(2, 1) = 8; a(2, 2) = 9;
			assert_vcl_no_msg(a[0] == 1);
			assert_vcl_no_msg(a[1] == 4);
			assert_vcl_no_msg(a[2] == 7);
			assert_vcl_no_msg(a[3] == 2);
			assert_vcl_no_msg(a[4] == 5);
			assert_vcl_no_msg(a[5] == 8);
			assert_vcl_no_msg(a[6] == 3);
			assert_vcl_no_msg(a[7] == 6);
			assert_vcl_no_msg(a[8] == 9);

			vcl::grid_2D<int> b(3, 3);
			b(0, 0) = 0; b(0, 1) = -2; b(0, 2) = 0;
			b(1, 0) = -1; b(1, 1) = 1; b(1, 2) = 3;
			b(2, 0) = 2; b(2, 1) = -2; b(2, 2) = 1;

			vcl::grid_2D<int> c(3, 3);
			c(0, 0) = 1; c(0, 1) = 0; c(0, 2) = 3;
			c(1, 0) = 3; c(1, 1) = 6; c(1, 2) = 9;
			c(2, 0) = 9; c(2, 1) = 6; c(2, 2) = 10;
			assert_vcl_no_msg(is_equal(a + b, c));
		}


	}


	void text_grid_3D()
	{
		{
			vcl::grid_3D<int> a;
			a.resize(2, 2, 2);
			assert_vcl_no_msg(is_equal(a.dimension, vcl::size_t3{ 2,2,2 }));
			assert_vcl_no_msg(type_str(a) == "grid_3D<int>");

			int counter = 0;
			for (int kx = 0; kx < 2; ++kx)
				for (int ky = 0; ky < 2; ++ky)
					for (int kz = 0; kz < 2; ++kz)
						a(kx, ky, kz) = counter++;


			assert_vcl_no_msg(a(0, 0, 0) == 0);
			assert_vcl_no_msg(a(0, 0, 1) == 1);
			assert_vcl_no_msg(a(0, 1, 0) == 2);
			assert_vcl_no_msg(a(1, 1, 1) == 7);


			assert_vcl_no_msg(type_str(a) == "grid_3D<int>");
		}


	}

}

