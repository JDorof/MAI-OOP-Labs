#include <gtest/gtest.h>
#include "../src/figure_vector.cpp"
#include "../src/romb.cpp"
#include "../src/trapezium.cpp"
#include "../src/pentagon.cpp"

TEST(Construction, test_00)
{
    double test_eps = std::numeric_limits<double>::epsilon();
    Romb rb;
    Trapezium tr;
    Pentagon pt;
    ASSERT_TRUE((double(tr) - double(rb)) < test_eps);
    ASSERT_TRUE((double(pt) - double(tr)) < test_eps);
}

// -------------- Trapezium -------------

TEST(Trapezium, test_00)
{
    double test_eps = std::numeric_limits<double>::epsilon();
    Trapezium tr(
        Point(0.0, 0.0), 
        Point(1.0, 4.0), 
        Point(2.0, 4.0),
        Point(3.0, 0.0)
        );
    ASSERT_TRUE((double(tr) - 8) < test_eps);
}

TEST(Trapezium, test_01)
{
    double test_eps = std::numeric_limits<double>::epsilon();

    std::stringstream ss, sss;
    Trapezium tr;
    ss << "0 0 1 4 2 4 3 0";
    ss >> tr;
    sss << tr;
    EXPECT_EQ(sss.str(), "x  0, y  0\nx  1, y  4\nx  2, y  4\nx  3, y  0\n");
}

TEST(Trapezium, test_02)
{
    double test_eps = std::numeric_limits<double>::epsilon();
    Point p1(0.0, 0.0); 
    Point p2(1.0, 4.0);
    Point p3(2.0, 4.0);
    Point p4(3.0, 0.0);
    Trapezium tr1(p1, p2, p3, p4);
    ASSERT_TRUE((double(tr1) - 8) < test_eps);
}

TEST(Trapezium, test_03)
{
    double test_eps = std::numeric_limits<double>::epsilon();
    Trapezium tr1(
        Point(0.0, 0.0), 
        Point(1.0, 4.0), 
        Point(2.0, 4.0), 
        Point(3.0, 0.0)
    );
    Trapezium tr2(
        Point(0.0, 0.0), 
        Point(1.0, 4.0), 
        Point(2.0, 4.0), 
        Point(3.0, 0.0)
    );
    ASSERT_TRUE((double(tr1) - double(tr2)) < test_eps);
}

TEST(Trapezium, test_04)
{
    double test_eps = std::numeric_limits<double>::epsilon();
    Trapezium tr1(
        Point(0.0, 0.0), 
        Point(1.0, 4.0), 
        Point(2.0, 4.0), 
        Point(3.0, 0.0)
    );
    double x = 1.5;
    Point p(x, 2);
    ASSERT_TRUE(Point(tr1.get_center() - p).x_ < test_eps);
    ASSERT_TRUE(Point(tr1.get_center() - p).y_ < test_eps);
}


TEST(Trapezium, test_05)
{
    Trapezium tr;
    Trapezium tr1(
        Point(0.0, 0.0), 
        Point(1.0, 4.0), 
        Point(2.0, 4.0), 
        Point(3.0, 0.0)
    );
    Trapezium tr2(tr1);
    EXPECT_EQ(tr1, tr2);
    Trapezium tr3 = std::move(tr2);
    EXPECT_EQ(tr3, tr1);
    EXPECT_EQ(tr, tr2);
}

// --------------- Romb -------------------------

TEST(Romb, test_00)
{
    double test_eps = std::numeric_limits<double>::epsilon();
    Romb tr(
        Point(0.0, 0.0), 
        Point(-1.0, 2.0), 
        Point(0.0, 4.0), 
        Point(1, 2)
    );
    ASSERT_TRUE((double(tr) - 4) < test_eps);
}

TEST(Romb, test_01)
{
    double test_eps = std::numeric_limits<double>::epsilon();

    std::stringstream ss, sss;
    Romb rec;
    ss << "0 0 -1 2 0 4 1 2";
    ss >> rec;
    sss << rec;
    EXPECT_EQ(sss.str(), "x  0, y  0\nx  -1, y  2\nx  0, y  4\nx  1, y  2\n");
}

TEST(Romb, test_02)
{
    double test_eps = std::numeric_limits<double>::epsilon();
    Point p1(0.0, 0); 
    Point p2(-1.0, 2.0);
    Point p3(0.0, 4.0);
    Point p4(1.0, 2.0);
    Romb rec1(p1, p2, p3, p4);
    ASSERT_TRUE((double(rec1) - 4) < test_eps);
}

TEST(Romb, test_03)
{
    double test_eps = std::numeric_limits<double>::epsilon();
    Romb rec1(
        Point(0.0, 0.0), 
        Point(-2.0,2.0), 
        Point(0.0, 4.0), 
        Point(2, 2)
    );
    Romb rec2(
        Point(0.0, 0.0), 
        Point(-1.0,2.0), 
        Point(0.0, 4.0), 
        Point(1, 2)
    );
    ASSERT_TRUE((double(rec1) - 2*double(rec2)) < test_eps);
}

TEST(Romb, test_04)
{
    double test_eps = std::numeric_limits<double>::epsilon();
    Romb rec1(
        Point(0.0, 0.0), 
        Point(-1.0,2.0), 
        Point(0.0, 4.0), 
        Point(1, 2)
    );
    Point p(0, 2);
    ASSERT_TRUE(Point(rec1.get_center() - p).x_ < test_eps);
    ASSERT_TRUE(Point(rec1.get_center() - p).y_ < test_eps);
}


TEST(Romb, test_05)
{
    Romb rec;
    Romb rec1(
        Point(0.0, 0.0), 
        Point(-1.0,2.0), 
        Point(0.0, 4.0), 
        Point(1, 2)
    );
    Romb rec2(rec1);
    EXPECT_EQ(rec1, rec2);
    Romb rec3 = std::move(rec2);
    EXPECT_EQ(rec3, rec1);
    EXPECT_EQ(rec, rec2);
}

// --------- Pentagon --------

TEST(Pentagon, test_00)
{
    double test_eps = std::numeric_limits<double>::epsilon();
    Pentagon pt1(
        Point(0.0, 2.0), 
        Point(2.0, 0), 
        Point(1, -2), 
        Point(-1, -2),
        Point(-2, 0)
    );
    ASSERT_TRUE(double(pt1) - 10 < test_eps);
    Point p(5, 5);
    ASSERT_TRUE(Point(pt1.get_center() - p).x_ < test_eps);
    ASSERT_TRUE(Point(pt1.get_center() - p).y_ < test_eps);
}

TEST(Vector, test_03)
{
    double test_eps = std::numeric_limits<double>::epsilon();
    FigureVector vec;
    Trapezium tr1(
        Point(0.0, 0.0), 
        Point(1.0, 4.0), 
        Point(2.0, 4.0), 
        Point(3.0, 0.0)
    );
    for (int i = 0; i < 10; ++i){
        vec.push_back(&tr1);
    }
    ASSERT_TRUE(vec.size() == 10);
}

TEST(Vector, test_04)
{
    double test_eps = std::numeric_limits<double>::epsilon();
    FigureVector vec;
    Trapezium tr1(
        Point(0.0, 0.0), 
        Point(1.0, 4.0), 
        Point(2.0, 4.0), 
        Point(3.0, 0.0)
    );
    for (int i = 0; i < 10; ++i){
        vec.push_back(&tr1);
    }
    for (int i = 0; i < 5; ++i){
        vec.remove(0);
    }
    ASSERT_TRUE(vec.size() == 5);
    for (int i = 0; i < 4; ++i){
        ASSERT_TRUE((double(*vec.get(i)) - double(*vec.get(i+1))) < test_eps);
    }
}

TEST(Vector, test_05)
{
    double test_eps = std::numeric_limits<double>::epsilon();
    FigureVector vec;
    Trapezium tr1(
        Point(0.0, 0.0), 
        Point(1.0, 4.0), 
        Point(2.0, 4.0), 
        Point(3.0, 0.0)
    );
    for (int i = 0; i < 10; ++i){
        vec.push_back(&tr1);
    }
    for (int i = 0; i < 5; ++i){
        vec.remove(0);
    }
    ASSERT_TRUE(vec.size() == 5);
    for (int i = 0; i < 4; ++i){
        ASSERT_TRUE((double(*vec.get(i)) - double(*vec.get(i+1))) < test_eps);
    }
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}