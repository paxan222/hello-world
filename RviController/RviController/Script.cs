using System;
using System.IO;
using System.Windows;

namespace RviController
{
	class Script
	{
		/// <summary>
		/// Метод записи скрипта
		/// </summary>
		/// <param name="connectionProperties">параметры подлкючения</param>
		private void WriteScriptFile(CreateRequest createRequest)
		{
			var streamWriter = new StreamWriter("script.py");
			streamWriter.Write(createRequest.Script());
			streamWriter.Close();
		}
		/// <summary>
		/// Класс создающий скрипт с запросом
		/// </summary>
		public abstract class CreateRequest
		{
			/// <summary>
			/// Запрос, который будем вкладывать в скрипт
			/// </summary>
			protected string Request { get; set; }
			/// <summary>
			/// Хост
			/// </summary>
			private string Host { get; set; }
			/// <summary>
			/// Порт
			/// </summary>
			private string Port { get; set; }
			/// <summary>
			/// Адрес устройства
			/// </summary>
			private string IpAddress { get; set; }
			/// <summary>
			/// Переменная, содержащая скрипт
			/// </summary>
			/// <returns></returns>
			public string Script()
			{
				string script = string.Format("from socket import *" + Environment.NewLine + Environment.NewLine
									   + "host = '{0}'" + Environment.NewLine
									   + "port = {1}" + Environment.NewLine
									   + "sockobj = socket(AF_INET, SOCK_STREAM)" + Environment.NewLine
									   + "sockobj.setsockopt(SOL_SOCKET, SO_REUSEADDR, 1)" + Environment.NewLine
									   + "sockobj.bind((host, port))" + Environment.NewLine + Environment.NewLine
									   + "sockobj.connect(('{2}', 80))" + Environment.NewLine
									   + "#1d0902" + Environment.NewLine
									   + "#1cf4bf" + Environment.NewLine
									   + "#1cf4b4" + Environment.NewLine
									   + "sockobj.send(b\"\"\"POST /Quotation HTTP/1.1" + Environment.NewLine
									   + "Host: {0}" + Environment.NewLine
									   + "Content-Type: text/soap+xml; charset=utf-8" + Environment.NewLine
									   + "Authorization: Basic QWxhZGRpbjpPcGVuU2VzYW1l" + Environment.NewLine
									   + "Content-Length: nnn" + Environment.NewLine
									   + Request
									   + "\"\"\")" + Environment.NewLine
									   + "sockobj.close()", Host, Port, IpAddress);
				return script;
			}
			/// <summary>
			/// Конструктор класса
			/// Присваивает внутренним переменным подключения значения внешних переменных
			/// </summary>
			/// <param name="connectionProperties">Параметры подключения</param>
			protected CreateRequest(ConnectionProperties connectionProperties)
			{
				Host = connectionProperties.Host;
				Port = connectionProperties.Port;
				IpAddress = connectionProperties.IpAddress;
			}
			/// <summary>
			/// Метод открытия файла с запросом
			/// </summary>
			/// <param name="filename">имя файла</param>
			protected void OpenRequestFile(string filename)
			{
				try
				{
					Request = new StreamReader(filename).ReadToEnd();
				}
				catch (FileNotFoundException)
				{
					MessageBox.Show(string.Format("Файл \"{0}\" не найден в: {1}", filename, Environment.CurrentDirectory));
				}
			}
		}
		/// <summary>
		/// Класс, возвращающий скрипт с запросом "Добавление карты"
		/// </summary>
		private class CreateCredentialRequest : CreateRequest
		{
			public CreateCredentialRequest(ConnectionProperties connectionProperties)
				: base(connectionProperties)
			{
				const string filename = "CreateCredential.xml";
				OpenRequestFile(filename);
			}
		}
		/// <summary>
		/// Метод записывающий скрипт с запросом "Добавление карты"
		/// </summary>
		/// <param name="connectionProperties"></param>
		public void WriteCreateCredentialRequestScriptFile(ConnectionProperties connectionProperties)
		{
			WriteScriptFile(new CreateCredentialRequest(connectionProperties));
		}
		/// <summary>
		/// Класс, возвращающий скрипт с запросом "Удаление карты доступа по ее идентификатору из памяти контроллера"
		/// </summary>
		private class DeleteCredentialByIdRequest : CreateRequest
		{
			public DeleteCredentialByIdRequest(ConnectionProperties connectionProperties)
				: base(connectionProperties)
			{
				const string filename = "DeleteCredentialById.xml";
				OpenRequestFile(filename);
			}
		}
		/// <summary>
		/// Метод записывающий скрипт с запросом "Удаление карты доступа по ее идентификатору из памяти контроллера"
		/// </summary>
		/// <param name="connectionProperties"></param>
		public void WriteDeleteCredentialByIdRequestScriptFile(ConnectionProperties connectionProperties)
		{
			WriteScriptFile(new DeleteCredentialByIdRequest(connectionProperties));
		}
		/// <summary>
		/// Класс, возвращающий скрипт с запросом "Удаление всех карт из памяти контроллера"
		/// </summary>
		private class DeleteAllCredentialsRequest : CreateRequest
		{
			public DeleteAllCredentialsRequest(ConnectionProperties connectionProperties)
				: base(connectionProperties)
			{
				const string filename = "DeleteAllCredentials.xml";
				OpenRequestFile(filename);
			}
		}
		/// <summary>
		/// Метод записывающий скрипт с запросом "Удаление всех карт из памяти контроллера"
		/// </summary>
		/// <param name="connectionProperties"></param>
		public void WriteDeleteAllCredentialsRequestScriptFile(ConnectionProperties connectionProperties)
		{
			WriteScriptFile(new DeleteAllCredentialsRequest(connectionProperties));
		}
		/// <summary>
		/// Класс, возвращающий скрипт с запросом "Чтение параметров карт по идентификаторам"
		/// </summary>
		private class ReadCredentialParametersByIdRequest : CreateRequest
		{
			public ReadCredentialParametersByIdRequest(ConnectionProperties connectionProperties)
				: base(connectionProperties)
			{
				const string filename = "ReadCredentialParametersById.xml";
				OpenRequestFile(filename);
			}
		}
		/// <summary>
		/// Метод записывающий скрипт с запросом "Чтение параметров карт по идентификаторам"
		/// </summary>
		/// <param name="connectionProperties"></param>
		public void WriteReadCredentialParametersByIdRequestScriptFile(ConnectionProperties connectionProperties)
		{
			WriteScriptFile(new ReadCredentialParametersByIdRequest(connectionProperties));
		}
		/// <summary>
		/// Класс, возвращающий скрипт с запросом "Изменение параметров карты по ее идентификатору"
		/// </summary>
		private class EditCredentialByIdRequest : CreateRequest
		{
			public EditCredentialByIdRequest(ConnectionProperties connectionProperties)
				: base(connectionProperties)
			{
				const string filename = "EditCredentialById.xml";
				OpenRequestFile(filename);
			}
		}
		/// <summary>
		/// Метод записывающий скрипт с запросом "Изменение параметров карты по ее идентификатору"
		/// </summary>
		/// <param name="connectionProperties"></param>
		public void WriteEditCredentialByIdRequestScriptFile(ConnectionProperties connectionProperties)
		{
			WriteScriptFile(new EditCredentialByIdRequest(connectionProperties));
		}
		/// <summary>
		/// Класс, возвращающий скрипт с запросом "Чтение списка карт начиная с указанного идентификатора"
		/// </summary>
		private class ReadCredentialsFromIdRequest : CreateRequest
		{
			public ReadCredentialsFromIdRequest(ConnectionProperties connectionProperties)
				: base(connectionProperties)
			{
				const string filename = "ReadCredentialsFromId.xml";
				OpenRequestFile(filename);
			}
		}
		/// <summary>
		/// Метод записывающий скрипт с запросом "Чтение списка карт начиная с указанного идентификатора"
		/// </summary>
		/// <param name="connectionProperties"></param>
		public void WriteReadCredentialsFromIdRequestScriptFile(ConnectionProperties connectionProperties)
		{
			WriteScriptFile(new ReadCredentialsFromIdRequest(connectionProperties));
		}
		/// <summary>
		/// Класс, возвращающий скрипт с запросом "Выполнять запрос Enable Access Point"
		/// </summary>
		private class EnableAccessPointRequest : CreateRequest
		{
			public EnableAccessPointRequest(ConnectionProperties connectionProperties)
				: base(connectionProperties)
			{
				const string filename = "EnableAccessPoint.xml";
				OpenRequestFile(filename);
			}
		}
		/// <summary>
		/// Метод записывающий скрипт с запросом "Выполнять запрос Enable Access Point"
		/// </summary>
		/// <param name="connectionProperties"></param>
		public void WriteEnableAccessPointRequestScriptFile(ConnectionProperties connectionProperties)
		{
			WriteScriptFile(new EnableAccessPointRequest(connectionProperties));
		}
		/// <summary>
		/// Класс, возвращающий скрипт с запросом "Выполнять запрос Device Management -> SystemReboot"
		/// </summary>
		private class SystemRebootRequest : CreateRequest
		{
			public SystemRebootRequest(ConnectionProperties connectionProperties)
				: base(connectionProperties)
			{
				const string filename = "SystemReboot.xml";
				OpenRequestFile(filename);
			}
		}
		/// <summary>
		/// Метод записывающий скрипт с запросом "Выполнять запрос Device Management -> SystemReboot"
		/// </summary>
		/// <param name="connectionProperties"></param>
		public void WriteSystemRebootRequestScriptFile(ConnectionProperties connectionProperties)
		{
			WriteScriptFile(new SystemRebootRequest(connectionProperties));
		}
		/// <summary>
		/// Класс, возвращающий скрипт с запросом "Выполнять запрос Device Management -> SetSystemFactoryDefault (HardReset)"
		/// </summary>
		private class HardResetRequest : CreateRequest
		{
			public HardResetRequest(ConnectionProperties connectionProperties)
				: base(connectionProperties)
			{
				const string filename = "HardReset.xml";
				OpenRequestFile(filename);
			}
		}
		/// <summary>
		/// Метод записывающий скрипт с запросом "Выполнять запрос Device Management -> SetSystemFactoryDefault (HardReset)"
		/// </summary>
		/// <param name="connectionProperties"></param>
		public void WriteHardResetRequestScriptFile(ConnectionProperties connectionProperties)
		{
			WriteScriptFile(new HardResetRequest(connectionProperties));
		}
		/// <summary>
		/// Класс, возвращающий скрипт с запросом "Выполнять запрос Device Management -> SetSystemFactoryDefault (SoftReset)"
		/// </summary>
		private class SoftResetRequest : CreateRequest
		{
			public SoftResetRequest(ConnectionProperties connectionProperties)
				: base(connectionProperties)
			{
				const string filename = "SoftReset.xml";
				OpenRequestFile(filename);
			}
		}
		/// <summary>
		/// Метод записывающий скрипт с запросом "Выполнять запрос Device Management -> SetSystemFactoryDefault (SoftReset)"
		/// </summary>
		/// <param name="connectionProperties"></param>
		public void WriteSoftResetRequestScriptFile(ConnectionProperties connectionProperties)
		{
			WriteScriptFile(new SoftResetRequest(connectionProperties));
		}
	}
}
