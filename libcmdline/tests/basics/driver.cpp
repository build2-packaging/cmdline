#include <cmdline/cmdline.h>

#include <string>

#undef NDEBUG
#include <cassert>

int main ()
{
  using namespace std;

  cmdline::parser p;
  p.add<string> ("host", 'h', "host name", true, "");
  p.add<int> ("port", 'p', "port number", false, 80);
  p.add ("gzip", '\0', "gzip when transfer");

  const char* argv[] = {
    "prog",
    "--host=example.com",
    "-p", "443",
    "--gzip"
  };

  assert (p.parse (5, argv));
  assert (p.get<string> ("host") == "example.com");
  assert (p.get<int> ("port") == 443);
  assert (p.exist ("gzip"));
}
