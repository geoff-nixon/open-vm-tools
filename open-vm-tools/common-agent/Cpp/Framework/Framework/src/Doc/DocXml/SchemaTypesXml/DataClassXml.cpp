/*
 *  Author: bwilliams
 *  Created: April 6, 2012
 *
 *  Copyright (C) 2012-2016 VMware, Inc.  All rights reserved. -- VMware Confidential
 *
 *  This code was generated by the script "build/dev/codeGen/genCppXml". Please
 *  speak to Brian W. before modifying it by hand.
 *
 */

#include "stdafx.h"

#include "Doc/DocXml/SchemaTypesXml/ClassInstancePropertyXml.h"
#include "Doc/DocXml/SchemaTypesXml/ClassPropertyXml.h"

#include "Doc/SchemaTypesDoc/CClassInstancePropertyDoc.h"
#include "Doc/SchemaTypesDoc/CClassPropertyDoc.h"
#include "Doc/SchemaTypesDoc/CDataClassDoc.h"
#include "Xml/XmlUtils/CXmlElement.h"
#include "Doc/DocXml/SchemaTypesXml/DataClassXml.h"

using namespace Caf;

void DataClassXml::add(
	const SmartPtrCDataClassDoc dataClassDoc,
	const SmartPtrCXmlElement thisXml) {
	CAF_CM_STATIC_FUNC_VALIDATE("DataClassXml", "add");

	CAF_CM_ENTER {
		CAF_CM_VALIDATE_SMARTPTR(dataClassDoc);
		CAF_CM_VALIDATE_SMARTPTR(thisXml);

		const std::string namespaceValVal = dataClassDoc->getNamespaceVal();
		CAF_CM_VALIDATE_STRING(namespaceValVal);
		thisXml->addAttribute("namespace", namespaceValVal);

		const std::string nameVal = dataClassDoc->getName();
		CAF_CM_VALIDATE_STRING(nameVal);
		thisXml->addAttribute("name", nameVal);

		const std::string versionVal = dataClassDoc->getVersion();
		CAF_CM_VALIDATE_STRING(versionVal);
		thisXml->addAttribute("version", versionVal);

		const std::deque<SmartPtrCClassPropertyDoc> propertyVal =
			dataClassDoc->getPropertyCollection();
		if (! propertyVal.empty()) {
			for (TConstIterator<std::deque<SmartPtrCClassPropertyDoc> > propertyIter(propertyVal);
				propertyIter; propertyIter++) {
				const SmartPtrCXmlElement propertyXml =
					thisXml->createAndAddElement("property");
				ClassPropertyXml::add(*propertyIter, propertyXml);
			}
		}

		const std::deque<SmartPtrCClassInstancePropertyDoc> instancePropertyVal =
			dataClassDoc->getInstancePropertyCollection();
		if (! instancePropertyVal.empty()) {
			for (TConstIterator<std::deque<SmartPtrCClassInstancePropertyDoc> > instancePropertyIter(instancePropertyVal);
				instancePropertyIter; instancePropertyIter++) {
				const SmartPtrCXmlElement instancePropertyXml =
					thisXml->createAndAddElement("instanceProperty");
				ClassInstancePropertyXml::add(*instancePropertyIter, instancePropertyXml);
			}
		}

		const std::string uniqueVal = dataClassDoc->getUnique() ? "true" : "false";
		if (! uniqueVal.empty()) {
			thisXml->addAttribute("unique", uniqueVal);
		}

		const std::string transientValVal = dataClassDoc->getTransientVal() ? "true" : "false";
		if (! transientValVal.empty()) {
			thisXml->addAttribute("transient", transientValVal);
		}

		const std::string displayNameVal = dataClassDoc->getDisplayName();
		if (! displayNameVal.empty()) {
			thisXml->addAttribute("displayName", displayNameVal);
		}

		const std::string descriptionVal = dataClassDoc->getDescription();
		if (! descriptionVal.empty()) {
			thisXml->addAttribute("description", descriptionVal);
		}
	}
	CAF_CM_EXIT;
}

SmartPtrCDataClassDoc DataClassXml::parse(
	const SmartPtrCXmlElement thisXml) {
	CAF_CM_STATIC_FUNC_VALIDATE("DataClassXml", "parse");

	SmartPtrCDataClassDoc dataClassDoc;

	CAF_CM_ENTER {
		CAF_CM_VALIDATE_SMARTPTR(thisXml);

		const std::string namespaceValStrVal =
			thisXml->findRequiredAttribute("namespace");
		const std::string namespaceValVal = namespaceValStrVal;

		const std::string nameStrVal =
			thisXml->findRequiredAttribute("name");
		const std::string nameVal = nameStrVal;

		const std::string versionStrVal =
			thisXml->findRequiredAttribute("version");
		const std::string versionVal = versionStrVal;

		const CXmlElement::SmartPtrCElementCollection propertyChildrenXml =
			thisXml->findOptionalChildren("property");

		std::deque<SmartPtrCClassPropertyDoc> propertyVal;
		if (! propertyChildrenXml.IsNull() && ! propertyChildrenXml->empty()) {
			for (TConstIterator<CXmlElement::CElementCollection> propertyXmlIter(*propertyChildrenXml);
				propertyXmlIter; propertyXmlIter++) {
				const SmartPtrCXmlElement propertyXml = propertyXmlIter->second;
				const SmartPtrCClassPropertyDoc propertyDoc =
					ClassPropertyXml::parse(propertyXml);
				propertyVal.push_back(propertyDoc);
			}
		}

		const CXmlElement::SmartPtrCElementCollection instancePropertyChildrenXml =
			thisXml->findOptionalChildren("instanceProperty");

		std::deque<SmartPtrCClassInstancePropertyDoc> instancePropertyVal;
		if (! instancePropertyChildrenXml.IsNull() && ! instancePropertyChildrenXml->empty()) {
			for (TConstIterator<CXmlElement::CElementCollection> instancePropertyXmlIter(*instancePropertyChildrenXml);
				instancePropertyXmlIter; instancePropertyXmlIter++) {
				const SmartPtrCXmlElement instancePropertyXml = instancePropertyXmlIter->second;
				const SmartPtrCClassInstancePropertyDoc instancePropertyDoc =
					ClassInstancePropertyXml::parse(instancePropertyXml);
				instancePropertyVal.push_back(instancePropertyDoc);
			}
		}

		const std::string uniqueStrVal =
			thisXml->findOptionalAttribute("unique");
		bool uniqueVal = false;
		if (! uniqueStrVal.empty()) {
			uniqueVal = (uniqueStrVal.compare("true") == 0)  ? true : false;
		}

		const std::string transientValStrVal =
			thisXml->findOptionalAttribute("transient");
		bool transientValVal = false;
		if (! transientValStrVal.empty()) {
			transientValVal = (transientValStrVal.compare("true") == 0)  ? true : false;
		}

		const std::string displayNameStrVal =
			thisXml->findOptionalAttribute("displayName");
		const std::string displayNameVal = displayNameStrVal;

		const std::string descriptionStrVal =
			thisXml->findOptionalAttribute("description");
		const std::string descriptionVal = descriptionStrVal;

		dataClassDoc.CreateInstance();
		dataClassDoc->initialize(
			namespaceValVal,
			nameVal,
			versionVal,
			propertyVal,
			instancePropertyVal,
			uniqueVal,
			transientValVal,
			displayNameVal,
			descriptionVal);
	}
	CAF_CM_EXIT;

	return dataClassDoc;
}

