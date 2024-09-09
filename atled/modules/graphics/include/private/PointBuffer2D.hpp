#include <vector>

// Simple structure to represent a 2D point
struct Point2D {
  float x;
  float y;

  Point2D(float x_val = 0, float y_val = 0) : x(x_val), y(y_val) {}
};

class PointBuffer2D {
 public:
  // Constructor
  PointBuffer2D();

  // Destructor
  ~PointBuffer2D();

  // Add a point to the buffer
  void addPoint(float x, float y);

  // Get the point at a specific index
  Point2D getPoint(size_t index) const;

  std::vector<Point2D> GetBuffer();

  // Remove the point at a specific index
  void removePoint(size_t index);

  // Clear all points
  void clearBuffer();

  // Get the number of points
  size_t getSize() const;

  // Utility function to check if the buffer is empty
  bool isEmpty() const;

 private:
  std::vector<Point2D> buffer;  // A dynamic list of 2D points
};
