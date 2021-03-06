#ifndef WEBTOOLSCONFIG_H
#define WEBTOOLSCONFIG_H

#include "cl_config.h"

class WebToolsConfig : public clConfigItem
{
    size_t m_jsFlags;
    size_t m_xmlFlags;
    size_t m_htmlFlags;

public:
    virtual void FromJSON(const JSONElement& json);
    virtual JSONElement ToJSON() const;

    enum eJSFlags {
        kJSEnableCC = (1 << 0),
        kJSEnableVerboseLogging = (1 << 1),
        kJSLibraryJQuery = (1 << 2),
        kJSLibraryBrowser = (1 << 3),
        kJSLibraryEcma5 = (1 << 4),
        kJSLibraryEcma6 = (1 << 5),
        kJSLibraryChai = (1 << 6),
        kJSLibraryUnderscore = (1 << 7),
        kJSPluginNode = (1 << 8),
        kJSPluginStrings = (1 << 9),
        kJSPluginAngular = (1 << 10),
        kJSPluginQML = (1 << 11),

    };

    enum eHtmlFlags {
        kHtmlEnableCC = (1 << 0),
    };

    enum eXmlFlags {
        kXmlEnableCC = (1 << 0),
    };

protected:
    void EnableFlag(size_t& flags, int flag, bool b)
    {
        if(b) {
            flags |= flag;
        } else {
            flags &= ~flag;
        }
    }
    bool HasFlag(const size_t& flags, int flag) const { return flags & flag; }

public:
    WebToolsConfig();
    virtual ~WebToolsConfig();
    bool HasJavaScriptFlag(eJSFlags flag) const { return HasFlag(m_jsFlags, flag); }
    void EnableJavaScriptFlag(eJSFlags flag, bool b) { EnableFlag(m_jsFlags, flag, b); }

    bool HasXmlFlag(eXmlFlags flag) const { return HasFlag(m_xmlFlags, flag); }
    void EnableXmlFlag(eXmlFlags flag, bool b) { EnableFlag(m_xmlFlags, flag, b); }

    bool HasHtmlFlag(eHtmlFlags flag) const { return HasFlag(m_htmlFlags, flag); }
    void EnableHtmlFlag(eHtmlFlags flag, bool b) { EnableFlag(m_htmlFlags, flag, b); }
    
    /**
     * @brief create tern project file content based on the settings
     */
    wxString GetTernProjectFile() const;
    WebToolsConfig& Load();
    WebToolsConfig& Save();
};

#endif // WEBTOOLSCONFIG_H
