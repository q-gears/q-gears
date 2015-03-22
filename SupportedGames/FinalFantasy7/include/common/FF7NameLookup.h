/*
-----------------------------------------------------------------------------
Copyright (c) 15.10.2013 Tobias Peters <tobias.peters@kreativeffekt.at>

This file is part of Q-Gears

Q-Gears is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, version 2.0 (GPLv2) of the License.

Q-Gears is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.
-----------------------------------------------------------------------------
*/
#ifndef __FF7NameLookup_H__
#define __FF7NameLookup_H__

#include "common/TypeDefine.h"
#include "common/QGearsStringUtil.h"
#include "core/XmlFile.h"

namespace QGears
{
    namespace FF7
    {
        class FF7Metadata : public XmlFile
        {
        public:
            FF7Metadata(Ogre::String file)
                : XmlFile(file)
            {
                TiXmlNode* node = m_File.RootElement();

                if (node == nullptr || node->ValueStr() != "metadata")
                {
                    throw std::runtime_error("FF7Metadata: " + m_File.ValueStr() + " is not a valid metadata file! No <metadata> in root.");
                }

                node = node->FirstChild();
                while (node)
                {
                    if (node->Type() == TiXmlNode::TINYXML_ELEMENT && node->ValueStr() == "models")
                    {
                        ReadModels(node->FirstChild());
                    }
                    else if (node->Type() == TiXmlNode::TINYXML_ELEMENT && node->ValueStr() == "animations")
                    {
                        ReadAnimations(node->FirstChild());
                    }
                    else if (node->Type() == TiXmlNode::TINYXML_ELEMENT && node->ValueStr() == "scripts")
                    {
                        ReadScripts(node->FirstChild());
                    }

                    node = node->NextSibling();
                }
            }

            const String& Animation(const String &key) const
            {
                auto it = mAnimations.find(key);
                if (it != std::end(mAnimations))
                {
                    return it->second;
                }

                String base_name;
                StringUtil::splitBase(key, base_name);
                it = mAnimations.find(base_name);
                if (it != std::end(mAnimations))
                {
                    return it->second;
                }
                return key;
            }

            const String& Model(const String &key) const
            {
                auto it = mModels.find(key);
                if (it != std::end(mModels))
                {
                    return it->second;
                }

                String base_name;
                StringUtil::splitBase(key, base_name);
                it = mModels.find(base_name);
                if (it != std::end(mModels))
                {
                    return it->second;
                }
                return key;
            }

        private:
            void ReadModels(TiXmlNode* node)
            {
                while (node)
                {
                    const auto src = GetString(node, "name");
                    const auto dst = GetString(node, "target");
                    mModels[src] = dst;
                    node = node->NextSibling();
                }
            }

            void ReadAnimations(TiXmlNode* node)
            {
                while (node)
                {
                    const auto src = GetString(node, "name");
                    const auto dst = GetString(node, "target");
                    mAnimations[src] = dst;
                    node = node->NextSibling();
                }
            }

            void ReadScripts(TiXmlNode* node)
            {
                while (node)
                {
                    if (node->Type() == TiXmlNode::TINYXML_ELEMENT && node->ValueStr() == "CharacterIds")
                    {
                        ReadCharacterIds(node->FirstChild());
                    }
                    else if (node->Type() == TiXmlNode::TINYXML_ELEMENT && node->ValueStr() == "var_names")
                    {
                        ReadVarNames(node->FirstChild());
                    }
                    else if (node->Type() == TiXmlNode::TINYXML_ELEMENT && node->ValueStr() == "entity_names")
                    {
                        ReadEntityNames(node->FirstChild());
                    }
                    else if (node->Type() == TiXmlNode::TINYXML_ELEMENT && node->ValueStr() == "field")
                    {
                        const auto name = GetString(node, "name");
                        ReadField(node->FirstChild(), name);
                    }
                    node = node->NextSibling();
                }
            }

            void ReadField(TiXmlNode* node, const std::string& name)
            {
                while (node)
                {
                    if (node->Type() == TiXmlNode::TINYXML_ELEMENT && node->ValueStr() == "function")
                    {
                        ReadFunction(node, name);
                    }
                    else if (node->Type() == TiXmlNode::TINYXML_ELEMENT && node->ValueStr() == "entity")
                    {
                        const auto oldName = GetString(node, "name");
                        const auto newName = GetString(node, "new");
                        mFieldData[name].mEntityNameMap[oldName] = newName;
                    }
                    node = node->NextSibling();
                }
            }

            void ReadFunction(TiXmlNode* node, const std::string& fieldName)
            {
                const auto entityName = GetString(node, "entity_name");
                const auto oldFuncName = GetString(node, "name");
                const auto newFuncName = GetString(node, "new");
                const auto funcComment = GetString(node, "Comment");
                mFieldData[fieldName].mFunctionMap[entityName][oldFuncName] = std::make_pair(newFuncName, funcComment);
            }


            void ReadEntityNames(TiXmlNode* node)
            {
                while (node)
                {
                    if (node->Type() == TiXmlNode::TINYXML_ELEMENT && node->ValueStr() == "entity")
                    {
                        const auto oldName = GetString(node, "name");
                        const auto newName = GetString(node, "new");
                        mEntityNameMap[oldName] = newName;
                    }
                    node = node->NextSibling();
                }
            }

            void ReadVarNames(TiXmlNode* node)
            {
                while (node)
                {
                    if (node->Type() == TiXmlNode::TINYXML_ELEMENT && node->ValueStr() == "var")
                    {
                        const auto bank = GetInt(node, "Bank");
                        const auto address = GetInt(node, "Address");
                        const auto name = GetString(node, "Name");
                        mVarMap[bank][address] = name;
                    }
                    node = node->NextSibling();
                }
            }

            void ReadCharacterIds(TiXmlNode* node)
            {
                while (node)
                {
                    if (node->Type() == TiXmlNode::TINYXML_ELEMENT && node->ValueStr() == "char")
                    {
                        const auto id = GetInt(node, "Id");
                        const auto name = GetString(node, "Name");
                        mCharacterIds[id] = name;
                        node = node->NextSibling();
                    }
                    node = node->NextSibling();
                }
            }

            std::pair<String,String> FieldScriptFunctionData(const String& fieldName, const String& entityName, const String& oldFunctionName)
            {
                // Find a collection of field data for this field
                auto fieldIt = mFieldData.find(fieldName);
                if (fieldIt != std::end(mFieldData))
                {
                    // See if there is any info for this entity
                    auto entityIt = fieldIt->second.mFunctionMap.find(entityName);
                    if (entityIt != std::end(fieldIt->second.mFunctionMap))
                    {
                        // See if there is any info for this function in this entity
                        auto functionIt = entityIt->second.find(oldFunctionName);
                        if (functionIt != std::end(entityIt->second))
                        {
                            return  functionIt->second;
                        }
                    }
                }
                return std::make_pair("", "");
            }


            typedef std::map<String, String> LookupMap;
            LookupMap mModels;
            LookupMap mAnimations;
            std::map<int, String> mCharacterIds;
            std::map<int, std::map<int, String>> mVarMap;
            LookupMap mEntityNameMap;

            struct FieldMetaData
            {
                std::map<String, std::map<String, std::pair<String,String>>> mFunctionMap; // entity name to old function name finds new function name and comment
                LookupMap mEntityNameMap; // old name finds new name
            };
            std::map<String, FieldMetaData> mFieldData;
            friend class NameLookup;
        };

        class NameLookup
        {
        public:
            NameLookup() = delete;

            static String CharName(int charId)
            {
                auto it = Data().mCharacterIds.find(charId);
                if (it != std::end(Data().mCharacterIds))
                {
                    return it->second;
                }
                return std::to_string(charId);
            }

            static const String& animation(const String &key)
            {
                return Data().Animation(key);
            }

            static const String& model(const String &key)
            {
                return Data().Model(key);
            }

            static String FieldScriptVarName(int bank, int addr)
            {
                auto bankIt = Data().mVarMap.find(bank);
                if (bankIt != std::end(Data().mVarMap))
                {
                    auto addrIt = bankIt->second.find(addr);
                    if (addrIt != std::end(bankIt->second))
                    {
                        if (addrIt->second.empty() == false)
                        {
                            return addrIt->second;
                        }
                    }
                }
                return "";
            }

            static String FieldScriptEntityName(const String& oldEntityName)
            {
                auto it = Data().mEntityNameMap.find(oldEntityName);
                if (it != std::end(Data().mEntityNameMap))
                {
                    return it->second;
                }
                return oldEntityName;
            }

            static String FieldScriptFunctionComment(const String& fieldName, const String& entityName, const String& oldFunctionName)
            {
                return Data().FieldScriptFunctionData(fieldName, entityName, oldFunctionName).second;
            }

            static String FieldScriptFunctionName(const String& fieldName, const String& entityName, const String& oldFunctionName)
            {
                auto name = Data().FieldScriptFunctionData(fieldName, entityName, oldFunctionName).first;
                if (name.empty())
                {
                    return oldFunctionName;
                }
                return name;
            }

            static FF7Metadata& Data()
            {
                static FF7Metadata data("field_models_and_animation_metadata.xml");
                return data;
            }
        };
    }
}

#endif // __FF7NameLookup_H__
