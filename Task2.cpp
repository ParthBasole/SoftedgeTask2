#include <cstdlib>
#include <iostream>
#include <vector>


#include <opencv2/opencv.hpp>

int main(int argc, char* argv[]) {
  if (argc != 2) {
    cout<<"insufficient argument number";
  }

  
  cv::CascadeClassifier classifier(argv[1]);

  

  cv::namedWindow("Win1", CV_WINDOW_AUTOSIZE);

  cv::VideoCapture capture(0); 

  cv::Mat image;
  cv::Mat grayscale_image;
  Mat image = imread("image.jpg", IMREAD_GRAYSCALE);
  
    std::vector<cv::Rect> features;

    cv::cvtColor(image, grayscale_image, CV_BGR2GRAY);
    cv::equalizeHist(grayscale_image, grayscale_image);

    classifier.detectMultiScale(grayscale_image, features, 1.1, 2,
                                0 | CV_HAAR_SCALE_IMAGE, cv::Size(30, 30));

    
    for (auto&& feature : features) {
      cv::rectangle(image, feature, cv::Scalar(0, 255, 0), 2);
    }

    
    cv::imshow(window_name, image);

    
    switch (cv::waitKey(10)) {
      case 'q':
        std::exit(EXIT_SUCCESS);
      case 'Q':
        std::exit(EXIT_SUCCESS);
      default:
        break;
    }
  //}
  return EXIT_SUCCESS;
}
