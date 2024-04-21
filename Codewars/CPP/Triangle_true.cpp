namespace Triangle
{
  bool isTriangle(int a, int b, int c)
  {
    if (a + b > c && a + c > b && c + b > a)
    {
        return 1;
    }
    
    return false;
  }
};