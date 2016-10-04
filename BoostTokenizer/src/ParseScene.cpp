#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <boost/tokenizer.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/format.hpp>

// create a typecast to tokenizer as it's quicker to wrie than the whole
// line
typedef boost::tokenizer<boost::char_separator<char> > tokenizer;

/// @brief function to parse the Colour
/// @param _firstWord an iterator to the tokenizer
void parseColour(
                  tokenizer::iterator &_firstWord
                );
/// @brief function to parse the Translate
/// @param _firstWord an iterator to the tokenizer
void parseTranslate(
                    tokenizer::iterator  &_firstWord
                   );
/// @brief function to parse the Rotate
/// @param _firstWord an iterator to the tokenizer
void parseRotate(
                  tokenizer::iterator &_firstWord
                );
/// @brief function to parse the Sphere
/// @param _firstWord an iterator to the tokenizer
void parseSphere(
                  tokenizer::iterator &_firstWord
                );

/// @brief function to parse the Cube
/// @param _firstWord an iterator to the tokenizer
void parseCube(
                tokenizer::iterator &_firstWord
              );


/// main

int main(int argc, char *argv[])
{
  if (argc <=1)
  {
    std::cout <<"Usage FileRead [filename] "<<std::endl;
    exit(EXIT_FAILURE);
  }
  // open the file to parse
  std::fstream fileIn;
  fileIn.open(argv[1],std::ios::in);
  if (!fileIn.is_open())
  {
    std::cout <<"File : "<<argv[1]<<" Not found Exiting "<<std::endl;
    exit(EXIT_FAILURE);
  }

  // this is the line we wish to parse
  std::string lineBuffer;
  // say which separators should be used in this
  // case Spaces, Tabs and return \ new line
  boost::char_separator<char> sep(" \t\r\n");

  // loop through the file
  while(!fileIn.eof())
  {
    // grab a line from the input
    getline(fileIn,lineBuffer,'\n');
    // make sure it's not an empty line
    if(lineBuffer.size() !=0)
    {
      // now tokenize the line
      tokenizer tokens(lineBuffer, sep);
      // and get the first token
      tokenizer::iterator  firstWord = tokens.begin();
      // now see if it's a valid one and call the correct function
      if( *firstWord =="Colour")
      {
        parseColour(firstWord);
      }
      else if( *firstWord =="Translate")
      {
        parseTranslate(firstWord);
      }
      else if( *firstWord =="Rotate")
      {
        parseRotate(firstWord);
      }
      else if( *firstWord =="Sphere")
      {
        parseSphere(firstWord);
      }
      else if( *firstWord =="Cube")
      {
        parseCube(firstWord);
      }
      else
      {
        std::cerr<<"Unkown Token "<<*firstWord<<std::endl;
      }
    }
  }
  // close the file
  fileIn.close();
  return EXIT_SUCCESS;
}


void parseColour(
                  tokenizer::iterator &_firstWord
                )
{
  // skip first token
  ++_firstWord;
  // use lexical cast to convert to float then increment the itor
  float r=boost::lexical_cast<float>(*_firstWord++);
  float g=boost::lexical_cast<float>(*_firstWord++);
  float b=boost::lexical_cast<float>(*_firstWord++);
  // now print out values to prove it works
  std::cout<<(boost::format("Colour [%0.2f,%0.2f,%0.2f]\n") % r % g % b);
}
void parseTranslate(
                    tokenizer::iterator  &_firstWord
                   )
{
  // skip first token
  ++_firstWord;
  // use lexical cast to convert to float then increment the itor
  float x=boost::lexical_cast<float>(*_firstWord++);
  float y=boost::lexical_cast<float>(*_firstWord++);
  float z=boost::lexical_cast<float>(*_firstWord++);
  // now print out values to prove it works
  std::cout<<(boost::format("Translate [%0.2f,%0.2f,%0.2f]\n") % x % y % z);
}
void parseRotate(
                  tokenizer::iterator &_firstWord
                )
{
  // skip first token
  ++_firstWord;
  // use lexical cast to convert to float then increment the itor
  float angle=boost::lexical_cast<float>(*_firstWord++);
  float x=boost::lexical_cast<float>(*_firstWord++);
  float y=boost::lexical_cast<float>(*_firstWord++);
  float z=boost::lexical_cast<float>(*_firstWord++);

  // now print out values to prove it works
  std::cout<<(boost::format("Rotate %0.2f around [%0.2f,%0.2f,%0.2f]\n") %angle % x % y % z);
}
void parseSphere(
                 tokenizer::iterator &_firstWord
                )
{
  // skip first token
  ++_firstWord;
  // use lexical cast to convert to float then increment the itor
  float radius=boost::lexical_cast<float>(*_firstWord++);
  float x=boost::lexical_cast<float>(*_firstWord++);
  float y=boost::lexical_cast<float>(*_firstWord++);

  // now print out values to prove it works
  std::cout<<(boost::format("Sphere %0.2f %0.2f %0.2f\n") %radius % x % y );
}
void parseCube(
                tokenizer::iterator &_firstWord
              )
{
  // skip first token
  ++_firstWord;
  // use lexical cast to convert to float then increment the itor
  float width=boost::lexical_cast<float>(*_firstWord++);

  // now print out values to prove it works
  std::cout<<(boost::format("Cube %0.2f \n") %width );
}
