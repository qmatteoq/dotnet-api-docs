// System::Web::Services::Description.OperationFaultCollection->Add

/*
The following example demonstrates the 'Add' method of the
'OperationFaultCollection' class. Based on 'StockQuote_cs::wsdl', the program generates a WSDL file
'StockQuoteNew_cs::wsdl' which contains 'Fault' information written out.
*/

#using <System.dll>
#using <System.Web.Services.dll>
#using <System.Xml.dll>

using namespace System;
using namespace System::Web::Services::Description;
using namespace System::Xml;
using namespace System::Xml::Schema;
using namespace System::Xml::Serialization;

int main()
{
   try
   {
      // Read the 'StockQuote::wsdl' file as input.
      ServiceDescription^ myServiceDescription = ServiceDescription::Read( "StockQuote_cpp.wsdl" );
      PortTypeCollection^ myPortTypeCollection = myServiceDescription->PortTypes;
      PortType^ myPortType = myPortTypeCollection[ 0 ];
      OperationCollection^ myOperationCollection = myPortType->Operations;
      Operation^ myOperation = myOperationCollection[ 0 ];

      // <Snippet1>
      OperationFaultCollection^ myOperationFaultCollection = myOperation->Faults;
      OperationFault^ myOperationFault = gcnew OperationFault;
      myOperationFault->Name = "ErrorString";
      myOperationFault->Message = gcnew XmlQualifiedName( "s0:GetTradePriceStringFault" );
      myOperationFaultCollection->Add( myOperationFault );
      // </Snippet1>

      Console::WriteLine( "Added OperationFault with Name: {0}", myOperationFault->Name );
      myOperationFault = gcnew OperationFault;
      myOperationFault->Name = "ErrorInt";
      myOperationFault->Message = gcnew XmlQualifiedName( "s0:GetTradePriceIntFault" );
      myOperationFaultCollection->Add( myOperationFault );
      myOperationCollection->Add( myOperation );
      Console::WriteLine( "Added Second OperationFault with Name: {0}", myOperationFault->Name );
      myServiceDescription->Write( "StockQuoteNew_cpp.wsdl" );
      Console::WriteLine( "\nThe file 'StockQuoteNew_cpp.wsdl' is created  successfully." );
   }
   catch ( Exception^ e ) 
   {
      Console::WriteLine( "Exception caught!!!" );
      Console::WriteLine( "Source : {0}", e->Source );
      Console::WriteLine( "Message : {0}", e->Message );
   }
}
