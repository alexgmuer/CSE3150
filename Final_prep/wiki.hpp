#include <string>
#include <fstream>
#include <vector>

// Write in a class in order to read in from the personal_notes.md file,
// partition the sections into a class hierarchy, overload the >> operator
// so that the class object can be easily printed as a tree structure, 
// make it so that the definitions/section bodies can be extracted from the 
// class object using methods.

// Utilize virtual methods somehow

class Wiki {
    public:
    
    // Overall counts
    int numSections_Total{};
    int numSubsections_Total{};
    int numSubsubsections_Total{};
        
    // Name of wiki
    std::string name{};

    private:

    public:
    Wiki(std::string wiki_name = "Default_Wiki_Name") :
        numSections_Total{0},
        numSubsections_Total{0},
        numSubsubsections_Total{0},
        name{wiki_name}
    {}

    void read(const char* filename) {
        std::fstream filestream;
        filestream.open(filename);

        std::string line;
        std::vector<std::string> filelines;
        
        if (filestream.is_open()) {
            
            while (std::getline(filestream, line)) {
                filelines.push_back(line);
            }
        }

        for (int i = 0; i < filelines.size(); i++) {
            // Check the first couple characters of each line. It will either start with
            // '# ', '## ', '### ', or some other text. 

            std::string hash_4char = filelines[i].substr(0,3);
            std::string hash_3char = filelines[i].substr(0,2);
            std::string hash_2char = filelines[i].substr(0,1);

            if (hash_4char == "### ") {
                // Add to Subsubsection
            }
            if (hash_3char == "## ") {
                // Add to Subsubsection
                
            }
            if (hash_2char == "# ") {
                // Add to Subsubsection

            }
            // Else it is a line which is not a section, subsection, or subsubsection header. 
            // Should be added to the text body of the previous section, subsection, or subsubsection
        }


    }
};

class Section : public Wiki {
    public:
        // Number of subsections 
        int numSubsections{};
        int numSubsubsections{};

        // Vector of strings which represents the lines of text in each text body 
        std::vector<std::string> text_body{};
        
        // Name of section
        std::string name{};
    
    private:

    public:
    // Initialize numSubsections and numSubsubsections 
    // as zero when Subsection object is created
    Section(std::string section_name = "Default_Section_Name") :
        numSubsections{0},
        numSubsubsections{0},
        name{section_name},
        text_body{""}
    {}

    // Add subsection method
    
    // Add subsubsection method
    
};


class Subsection : public Section {
    public:
        // Number of subsubsections
        int numSubsubsections;
        
        // Name of subsection
        std::string name;
    private:

    public:
    // Initialize numSubsubsections as zero when Subsection object is created
    Subsection(std::string subsection_name = "Default_Subsection_Name") :
        numSubsubsections{0},
        name{subsection_name}
    {}
};

class Subsubsection : public Subsection {
    public:
        // Name of subsubsection
        std::string name;
    
    private:

    public:
    Subsubsection(std::string subsubsection_name = "Default_Subsubsection_Name") :
        name{subsubsection_name}
    {}
};

std::ostream& operator<<(std::ostream& os, const Wiki* wiki) {
    // Iterate through wiki sections, subsections, and subsubsections
    // Print out as a tree like this:
    /*
    
    Wiki_name:
    |_Section1
    |   |_Subsection1
    |   |   |_Subsubsection11
    |   |_Subsection2
    |       |_Subsubsection21
    |_Section2
    
    */
    
    // In order to do this the following must be known:
    // Wiki name 
    // Number of sections (Overall)
    // Number of subsections (Both for each section and overall)
    // Number of subsubsections (Both for each subsection and overall)


    return os;
}