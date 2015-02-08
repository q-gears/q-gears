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
        class FF7FiledModelsAndAnimationMetadata : public XmlFile
        {
        public:
            FF7FiledModelsAndAnimationMetadata(Ogre::String file)
                : XmlFile(file)
            {
                TiXmlNode* node = m_File.RootElement();

                if (node == nullptr || node->ValueStr() != "metadata")
                {
                    throw std::runtime_error("FF7FiledModelsAndAnimationMetadata: " + m_File.ValueStr() + " is not a valid metadata file! No <metadata> in root.");
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

            typedef std::map<String, String> LookupMap;
            LookupMap mModels;
            LookupMap mAnimations;
        };

        class NameLookup
        {
        public:
            NameLookup() = delete;

            static const String& animation(const String &key)
            {
                return Data().Animation(key);
            }

            static const String& model(const String &key)
            {
                return Data().Model(key);
            }

            static FF7FiledModelsAndAnimationMetadata& Data()
            {
                static FF7FiledModelsAndAnimationMetadata data("field_models_and_animation_metadata.xml");
                return data;
            }
        };
    }
}

#endif // __FF7NameLookup_H__
