#ifndef JSSOURCEFILE_H
#define JSSOURCEFILE_H

#include "codelite_exports.h"
#include <wx/string.h>
#include <wx/filename.h>
#include <vector>
#include "JSLexerAPI.h"
#include "JSObject.h"
#include "JSLookUpTable.h"

class JSObjectParser;
class WXDLLIMPEXP_CL JSSourceFile
{
    JSScanner_t m_scanner;
    wxFileName m_filename;
    JSLookUpTable::Ptr_t m_lookup;
    int m_depth;
    JSLexerToken m_lastToken;
    JSLexerToken m_lastCommentBlock;

    friend class JSObjectParser;
    bool m_EOF;

protected:
    bool ReadSignature(JSObject::Ptr_t scope);
    void ParseFunction(JSObject::Ptr_t scope);
    bool ReadUntil(int until, wxString& content);
    bool ReadUntilExcluding(int until, wxString& content);
    bool ReadUntil2(int until, int until2, wxString& content);

    // Actions
    JSObject::Ptr_t OnFunction();
    JSObject::Ptr_t OnVariable();
    JSObject::Ptr_t OnReturnValue();
    /**
     * @brief handle this.<something>... while inside a function
     */
    void OnFunctionThisProperty();
    /**
     * @brief Attempt to parse Class[.prototype].Foo
     */
    void OnPropertyOrFunction(JSObject::Ptr_t This);

    bool NextToken(JSLexerToken& token);
    void UngetToken(const JSLexerToken& token);

    /**
     * @brief try to match the comment to an object
     */
    void AssociateComment(JSObject::Ptr_t obj);

    /**
     * @brief create a JS object from a JSON string
     */
    JSObject::Ptr_t ParseJSONObject(const wxString& content);

public:
    JSSourceFile(JSLookUpTable::Ptr_t lookup, const wxString& fileContent, const wxFileName& filename);
    JSSourceFile(JSLookUpTable::Ptr_t lookup, const wxFileName& filename);

    virtual ~JSSourceFile();
    /**
     * @brief return the nesting level 
     */
    int GetDepth() const { return m_depth; }
    void Parse(int exitDepth = -1);
};

#endif // JSSOURCEFILE_H