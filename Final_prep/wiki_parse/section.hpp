#include <vector>
#include <memory>
#include <map>
#include <string>

class Subsection;
class Subsubsection;

class Section {
    public:
        // Number of subsections 
        int numSubsections{};
        int numSubsubsections{};

        // Vector of strings which represents the lines of text in each text body 
        std::vector<std::string> text_body{};
        
        // Map to subsections
        std::map<std::string, std::shared_ptr<Subsection>> subsections_map;

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
        
        // Vector of strings which represents the lines of text in each text body 
        std::vector<std::string> text_body{};
        
        // Subsubsections map
        std::map<std::string, std::shared_ptr<Subsubsection>> subsubsections_map;

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

        // Vector of strings which represents the lines of text in each text body 
        std::vector<std::string> text_body{};

    
    private:

    public:
    Subsubsection(std::string subsubsection_name = "Default_Subsubsection_Name") :
        name{subsubsection_name}
    {}

};