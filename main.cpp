#include <cstdlib>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <vector>

using namespace std;
using namespace cv;

Point2f transformPoint(Mat const& m, Point2f const& pt)
{
  Mat pt_homogeneous(3, 1, CV_64F);
  pt_homogeneous.at<double>(0, 0) = pt.x;
  pt_homogeneous.at<double>(1, 0) = pt.y;
  pt_homogeneous.at<double>(2, 0) = 1;
  Mat res = m * pt_homogeneous;
  return Point2f(
    static_cast<float>(res.at<double>(0, 0) / res.at<double>(2, 0)),
    static_cast<float>(res.at<double>(1, 0) / res.at<double>(2, 0))
    );
}

int main(int argc, char* argv[])
{
  vector<Point2f> src;
  vector<Point2f> dst;

  src.push_back(Point2f(0.f, 0.f));
  src.push_back(Point2f(100.f, 0.f));
  src.push_back(Point2f(0.f, 100.f));
  src.push_back(Point2f(100.f, 100.f));

  dst.push_back(Point2f(0.f, 0.f));
  dst.push_back(Point2f(100.f, 0.f));
  dst.push_back(Point2f(0.f, 100.f));
  dst.push_back(Point2f(75.f, 75.f));

  auto ts2d = getPerspectiveTransform(src, dst);
  cout << ts2d << endl;

  auto td2s = getPerspectiveTransform(dst, src);
  cout << td2s << endl;

  auto s2d = transformPoint(ts2d, src[3]);
  cout << s2d << endl;

  auto d2s = transformPoint(td2s, dst[3]);
  cout << d2s << endl;

  return EXIT_SUCCESS;
}