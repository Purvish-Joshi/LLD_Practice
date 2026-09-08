#include <iostream>
#include <string>
#include <memory>
using namespace std;

class ReportExporter
{
public:
    virtual void exportReport(const string &content) = 0;
    virtual ~ReportExporter() = default;
};

class PdfExporter : public ReportExporter
{
public:
    void exportReport(const string &content) override
    {
        cout << content << "is exported in Pdf form" << endl;
    }
};

class CsvExporter : public ReportExporter
{
public:
    void exportReport(const string &content) override
    {
        cout << content << "is exported in Csv form" << endl;
    }
};

class ExcelExporter : public ReportExporter
{
public:
    void exportReport(const string &content) override
    {
        cout << content << "is exported in Excel form" << endl;
    }
};

class ReportCreator
{
public:
    void generateReport(const string &content)
    {
        auto reportExporter = createReport();

        reportExporter->exportReport(content);
    }

    virtual unique_ptr<ReportExporter>
    createReport() = 0;

    virtual ~ReportCreator() = default;
};

class PdfCreator : public ReportCreator
{
public:
    unique_ptr<ReportExporter> createReport() override
    {
        return make_unique<PdfExporter>();
    }
};

class CsvCreator : public ReportCreator
{
public:
    unique_ptr<ReportExporter> createReport() override
    {
        return make_unique<CsvExporter>();
    }
};

class ExcelCreator : public ReportCreator
{
public:
    unique_ptr<ReportExporter> createReport() override
    {
        return make_unique<ExcelExporter>();
    }
};

int main()
{

    unique_ptr<ReportCreator> rp = make_unique<PdfCreator>();

    rp->generateReport("this is my message ");

    return 0;
}