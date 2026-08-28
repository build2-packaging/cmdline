#include <cmdline/cmdline.h>

#include <string>
#include <vector>

#undef NDEBUG
#include <cassert>

static void
test_stop_at_rest ()
{
  using namespace std;

  cmdline::parser p;
  p.add<uint32_t> ("count", 'c', "how many", false, 1);
  p.set_header ("<target>");
  p.set_footer ("[target arguments]");
  p.stop_at_rest (true);

  const string usage (p.usage ());
  assert (usage.find ("<target>") != string::npos);
  assert (usage.find ("[target arguments]") != string::npos);

  vector<string> args {"--count", "3", "prog", "--unknown", "-x"};

  assert (p.parse (args, true));
  assert (p.get<uint32_t> ("count") == 3);

  const vector<string> &rest (p.rest ());
  assert (rest.size () == 3);
  assert (rest[0] == "prog");
  assert (rest[1] == "--unknown");
  assert (rest[2] == "-x");
}

static void
test_set_rest ()
{
  cmdline::parser p;

  std::vector<std::string> replaced {"a", "b"};
  p.set_rest (replaced);
  assert (p.rest () == replaced);
}

static void
test_range_and_oneof_errors ()
{
  using namespace std;

  bool threw = false;
  try
  {
    cmdline::range (5, 20) ("42");
  }
  catch (const cmdline::cmdline_error &e)
  {
    threw = true;
    const string what (e.what ());
    assert (!what.empty ());
    assert (what.find ("5") != string::npos);
    assert (what.find ("20") != string::npos);
  }
  assert (threw);

  threw = false;
  try
  {
    cmdline::oneof<string> ("aa", "bb") ("zz");
  }
  catch (const cmdline::cmdline_error &e)
  {
    threw = true;
    const string what (e.what ());
    assert (!what.empty ());
    assert (what.find ("zz") != string::npos);
  }
  assert (threw);
}

int
main ()
{
  test_stop_at_rest ();
  test_set_rest ();
  test_range_and_oneof_errors ();
}
